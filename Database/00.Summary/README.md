### Simple Definition

* Database : A collection of related data
* Data : Known facts that can be recorded and have an implicit meaning
* Miniworld : Some part of the real world about which data is stored in a database
* DBMS : A software package
* Database System : The DBMS software together with the data itself

* Defining a database : data types, structures, constraints ...
* Meta-data : Database definition or descriptive information

### Characteristics of the Database

* Traditional file processing
* Database approach
* Self-describing
* Insulation between programs and data
  * program-data independence
  * program-operation independence
* multiple views
* multiuser

### Advandages of Using the DBMS

* Controlling redundancy
  * Data normalization

### Not to use DBMS

* not expected to change
* real-time
* embedded system with limited storage capacity
* no multiple-user

### Data Model

* Construct : to define the database structure
* Constraint : some restrictions on valid data

* Conceptual data model
* Physical data model

### Schema & Instance

* Database Schema : The description of a database
* Schema Diagram : An illustrative display of a database schema

### Schema & State

* Schema changes very infrequently (like column)
* State changes every time when database is updated (column, rows)

### Three Schema Architecture

* Internal Schema : describe physical storage
* Conceptual Schema : describe structure and constraint
* External Schema : describe the various user views

### Data Independence

* Logical Data Independence : change conceptual schema without changing external schema
* Physical Data Independence : change internal schema without changing conceptual schema

### Relational Data Model

* domain : data-type or format (varchar, date...)
* domain constraint : 모든 튜플은 도메인에 따른 값을 가져야 한다.
* key constraint : 
* Entity integrity constraint : primary key 는 NULL 을 가질 수 없다.
* Referential integrity constraint : 참조 받는 컬럼은 PK 이어야 한다.

* update
  * domain 위반 할 수 있음, 중복된 키값일 수 있음, pk 가 null 일 수 있음, FK 가 존재하지 않을 수 있음

