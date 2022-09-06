## Missing Index

동적쿼리의 경우 아래 쿼리를 통해 실행계획을 확인할 수 있다.

```sql
SELECT usecounts, cacheobjtype, objtype, text, query_plan, value as set_options
FROM sys.dm_exec_cached_plans
CROSS APPLY sys.dm_exec_sql_text(plan_handle)
CROSS APPLY sys.dm_exec_query_plan(plan_handle)
CROSS APPLY sys.dm_exec_plan_attributes(plan_handle) AS epa
WHERE text LIKE '%Some unique string in your query%' AND attribute = 'set_options'
```

SP_EXECUTESQL 의 경우 objtype = 'Prepared' 이다.  
query_plan 의 링크를 눌러 실행계획을 확인할 수 있다.  
실행계획에 Missing Index 라는 문구가 들어있다면 인덱스를 활용하여 성능이 증가할 수 있다는 뜻이다.
