# Concept and Architecture

## Data Model

* Constructs are used to define the database structure
* Constructs typically include elements as well as groups of elements, and relationships among such groups
* Constraints specify some restrictions on valid data

## Schemas vs Instances

* Database Schema
   * The description of a database
   * Include descriptions of the database structure, data types, and the constraints on the database
* Schema Diagram
   * An illustrative display of a database schema
* Schema Construct
   * A component of the schema or an object within the schema (e.g., STUDENT, COURSE)
* Database Instance
   * The term instance is also applied to individual database components (e.g., record instance, table instance, entity instance)
* Database State
   * The actual data stored in a database at a particular moment in time. This includes the collection of all the data in the database

### Database Schema vs Database State

* The database schema changes very infrequently
* The database state changes every time the database is updated
* Schema is also called intension (COLUMN)
* State is also called extension (COLUMN, ROWS)

### Three-Schema Architecture

![image](https://user-images.githubusercontent.com/48989903/163157985-6846faa3-a6da-4f50-9906-11f4468ec692.png)

* Internal schema at the internal level to describe physical storage structures and access paths (e.g., indexes)
* Conceptual schema at the conceptual level to describe the structure and constraints for the whole database for a community of users
* External schemas at the external level to describe the various user views 

### Data Independence

* Logical Data Independence : The capacity to change the conceptual schema without having to change the external schema
* Physical Data Independence : The capacity to change the internal schema without having to change the conceptual schema

## DBMS Languages

* Data Definition Language : DDL is used by the DBA and by database designer to define conceptual and internal schemas
* Data Manipulation Language : used to specify database retrievals and updates
   * High level or Non-procedural language : the SQL relational language
   * Low level or Procedural language : retrieve data one record-at-a-time

