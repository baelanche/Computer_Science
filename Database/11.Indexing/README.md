# Indexing

Motivation : A data structure for efficient search through large databases

* The records are mapped to the disk blocks in <b>specific</b> ways

## Index as Access Paths

An index is an auxiliary file that makes it more efficient to search for a record in the data file

* Indexes can be characterized as dense or sparse
  * dense : every search key value
  * sparse : only some of the search value
* Indexes can be represented by sorted lists or hashing

### Primary Index

* case : without primary index
* case : primary index

### Secondary Index

* A secondary index is a secondary means of accessing a file
* The index is an ordered file with two fields
* It is a dense index

