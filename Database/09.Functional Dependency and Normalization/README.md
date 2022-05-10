## Informal Guidelines

### Measures of quality
 
* Making sure attributes semantics are clear
* Reducing redundant information in tuples
* Reducing NULL values in tuples
* Disallowing possibility of generating spurious tuples

### each tuple should represent one entity or relationship instance

### information is stored redundantly

### insert anomaly

* 다른 attribute 가 없으면 특정 attribute 를 삽입할 수 없는 경우

### delete anomaly

* 하나의 속성에 대해서 정보를 삭제할 때 필요로 하는 다른 정보도 함께 삭제해야되는 경우

### update anomaly

* 하나의 속성에 대해서 정보를 수정하는 경우 데이터의 불일치가 발생되는 경우

## Functional Dependency

attribute set A와 B가 모두 relation R에 속할 때, A의 값이 항상 B의 값을 결정하면 B는 A에 함수 종속된다고 한다.  
즉, A⊆R, B⊆R 일 때, 임의의 tuple1과 tuple2의 A 값이 같을 때, B의 값도 같다면 A→B 이다.  
이 때, attribute set A를 determinant set(결정자), B를 dependent set(종속자)라고 한다.

## Database Normalization

데이터를 일정한 형태와 규칙에 맞춰 구조화 함으로써 anomaly 를 줄이는 작업을 말한다. 
데이터베이스를 정규화하기 위한 형태와 규칙들을 <b>Normal Form</b> 으로 정의하여 분류한다.  
기본적인 <b>Normal Form</b> 으로는 1NF, 2NF, 3NF, BCNF 등이 있다.

### Normal Form

#### First Normal Form (1NF)

* 모든 attribute 값은 atomic 해야 한다. (no composite, multi-value)

#### Second Normal Form (2NF)

* 1NF 를 만족해야 한다.
* Partial Functional Dependency 가 존재하지 않아야 한다. (모든 attribute 는 모든 key 에 종속되어야 한다)

#### Third Normal Form (3NF)

* 2NF 를 만족해야 한다.
* Transitive Functional Dependency 가 존재하지 않아야 한다.

