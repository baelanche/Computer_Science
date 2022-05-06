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

