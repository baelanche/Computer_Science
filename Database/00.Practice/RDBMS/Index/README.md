# Index

쿼리 실행 순서 :
```
FROM - WHERE - GROUP BY - HAVING - SELECT - ORDER BY
```

where 절을 어떻게 설계하느냐에 따라 full scan 을 할지 index 를 활용한 scan 을 할지 결정된다.

## 인덱스를 타지 않는 경우

#### 1. LIKE '%_'

```sql
SELECT * FROM tbl WHERE name LIKE '%Tom'
SELECT * FROM tbl WHERE name LIKE '%Tom%'
```

위의 경우에는 인덱스를 타지 않는다.  
인덱스를 걸면 해당 컬럼은 정렬이 되므로 정렬된 문자열의 앞부분부터 스캔하게 되는데, 위 쿼리에서는 그것이 불가능하기 때문이다.

```sql
SELECT * FROM tbl WHERE name LIKE 'Tom%'
```

위 쿼리는 인덱스를 탈 수 있다.

#### 2. Type

```sql
CREATE TABLE tbl (
    id int NOT NULL
)

SELECT * FROM tbl WHERE id = '1'
```

인덱스를 타게 하기 위해서는 컬럼의 타입을 맞춰주어야 한다.

#### 3. OR

OR 연산자를 사용하면 앞, 뒤 조건을 무조건 확인해야 하므로 인덱스가 걸려있어도 인덱스가 걸려있지 않은 컬럼을 따라 풀 스캔을 하게 된다.  
OR 연산자에 관계된 모든 컬럼이 복합키로 설정되어 있지 않다면 인덱스를 타지 않는다.

#### 4. 형변환/값변환

```sql
SELECT * FROM tbl WHERE CAST(id AS CHAR) = "0"  -- 1
SELECT * FROM tbl WHERE id = CAST(0 AS CHAR)    -- 2
```

1번은 인덱스를 타지 않고 2번은 인덱스를 탄다.  
형변환을 할 때에는 우측의 조건에 걸어주는게 좋다.

```sql
SELECT * FROM tbl WHERE salary * 100 = 10000  -- 1
SELECT * FROM tbl WHERE salary = 10000 / 100  -- 2
```

이때도 마찬가지로 1번은 인덱스를 타지 않고 2번은 인덱스를 탄다.

#### 5. 부정문

!=, <>, NOT IN, NOT EXISTS 등은 인덱스를 타지 않는다.

> `<`, `<=` 등은 인덱스를 탄다.

#### 6. NULL

IS NULL, IS NOT NULL 은 인덱스를 타지 않는다.

#### 7. 인덱스 끼리의 비교

```sql
SELECT *
FROM   employee AS A
       INNER JOIN department AS B
       ON A._empId = B._empId
```

인덱스 컬럼끼리 비교할 때 왼쪽의 컬럼만 인덱스를 탄다.
