/**
*AUTHORS: <Itay Simhayev 205666407>
 * Date: 2020-04
 */
#include "doctest.h"
#include "FamilyTree.hpp"
#include <string>

using namespace std;
using namespace family;


TEST_CASE("Test addFather and addMother")
{
    family::Tree T ("Yosef"); // Yosef is the "root" of the tree (the youngest person).
	T.addFather("Yosef", "Yaakov")   // Tells the tree that the father of Yosef is Yaakov.
	 .addMother("Yosef", "Rachel")   // Tells the tree that the mother of Yosef is Rachel.
	 .addFather("Yaakov", "Isaac")
	 .addMother("Yaakov", "Rivka")
	 .addFather("Isaac", "Avraham")
     .addMother("Isaac", "Sarah")
	 .addFather("Avraham", "Terah")
	 .addMother("Avraham", "Bella")
	 .addFather("Bella", "Alex")
	 .addFather("Rachel", "Dani")
	 .addMother("Rachel", "Tami")
	 .addFather("Tami", "Yosi")
	 .addMother("Dani", "Roze")
	 .addMother("Roze", "Orna")
	 .addFather("Roze", "Roban");
    CHECK_THROWS(T.addFather("Benni", "itay")); //Benni is not in the family tree
    CHECK_THROWS(T.addFather("Yosef", "Yaakov")); //Yosef has a father already
    CHECK( T.relation("Yaakov") ==string("father"));
    CHECK( T.relation("Rachel") ==string("mother"));
    CHECK( T.relation("Isaac") ==string("grandfather"));
    CHECK( T.relation("Rivka") ==string("grandmother"));
    CHECK( T.relation("Avraham") ==string("great-grandfather"));
    CHECK( T.relation("Sarah") ==string("great-grandmother"));
    CHECK( T.relation("Terah") ==string("great-great-grandfather"));
    CHECK(T.relation("Yosef")==string("me"));
    CHECK( T.relation("Bella") ==string("great-great-grandmother"));
    CHECK( T.relation("Alex") ==string("great-great-great-grandfather"));
    CHECK( T.relation("Dani") ==string("grandfather"));
    CHECK( T.relation("Tami") ==string("grandmother"));
    CHECK( T.relation("Roze") ==string("great-grandmother"));
    CHECK( T.relation("Yosi") ==string("great-grandfather"));
    CHECK( T.relation("Orna") ==string("great-great-grandmother"));
    CHECK( T.relation("Roban") ==string("great-great-grandfather"));
    
    
    
    
       CHECK_THROWS(T.addFather("Benni", "itay")); //Benni is not in the family tree
    CHECK_THROWS(T.addFather("Yosef", "Yaakov")); //Yosef has a father already
    CHECK( T.relation("Yaakov") ==string("father"));
    CHECK( T.relation("Rachel") ==string("mother"));
    CHECK( T.relation("Isaac") ==string("grandfather"));
    CHECK( T.relation("Rivka") ==string("grandmother"));
    CHECK( T.relation("Avraham") ==string("great-grandfather"));
    CHECK( T.relation("Sarah") ==string("great-grandmother"));
    CHECK( T.relation("Terah") ==string("great-great-grandfather"));
    CHECK(T.relation("Yosef")==string("me"));
    CHECK( T.relation("Bella") ==string("great-great-grandmother"));
    CHECK( T.relation("Alex") ==string("great-great-great-grandfather"));
    CHECK( T.relation("Dani") ==string("grandfather"));
    CHECK( T.relation("Tami") ==string("grandmother"));
    CHECK( T.relation("Roze") ==string("great-grandmother"));
    CHECK( T.relation("Yosi") ==string("great-grandfather"));
    CHECK( T.relation("Orna") ==string("great-great-grandmother"));
    CHECK( T.relation("Roban") ==string("great-great-grandfather"));
       CHECK_THROWS(T.addFather("Benni", "itay")); //Benni is not in the family tree
    CHECK_THROWS(T.addFather("Yosef", "Yaakov")); //Yosef has a father already
    CHECK( T.relation("Yaakov") ==string("father"));
    CHECK( T.relation("Rachel") ==string("mother"));
    CHECK( T.relation("Isaac") ==string("grandfather"));
    CHECK( T.relation("Rivka") ==string("grandmother"));
    CHECK( T.relation("Avraham") ==string("great-grandfather"));
    CHECK( T.relation("Sarah") ==string("great-grandmother"));
    CHECK( T.relation("Terah") ==string("great-great-grandfather"));
    CHECK(T.relation("Yosef")==string("me"));
    CHECK( T.relation("Bella") ==string("great-great-grandmother"));
    CHECK( T.relation("Alex") ==string("great-great-great-grandfather"));
    CHECK( T.relation("Dani") ==string("grandfather"));
    CHECK( T.relation("Tami") ==string("grandmother"));
    CHECK( T.relation("Roze") ==string("great-grandmother"));
    CHECK( T.relation("Yosi") ==string("great-grandfather"));
    CHECK( T.relation("Orna") ==string("great-great-grandmother"));
    CHECK( T.relation("Roban") ==string("great-great-grandfather"));
       CHECK_THROWS(T.addFather("Benni", "itay")); //Benni is not in the family tree
    CHECK_THROWS(T.addFather("Yosef", "Yaakov")); //Yosef has a father already
    CHECK( T.relation("Yaakov") ==string("father"));
    CHECK( T.relation("Rachel") ==string("mother"));
    CHECK( T.relation("Isaac") ==string("grandfather"));
    CHECK( T.relation("Rivka") ==string("grandmother"));
    CHECK( T.relation("Avraham") ==string("great-grandfather"));
    CHECK( T.relation("Sarah") ==string("great-grandmother"));
    CHECK( T.relation("Terah") ==string("great-great-grandfather"));
    CHECK(T.relation("Yosef")==string("me"));
    CHECK( T.relation("Bella") ==string("great-great-grandmother"));
    CHECK( T.relation("Alex") ==string("great-great-great-grandfather"));
    CHECK( T.relation("Dani") ==string("grandfather"));
    CHECK( T.relation("Tami") ==string("grandmother"));
    CHECK( T.relation("Roze") ==string("great-grandmother"));
    CHECK( T.relation("Yosi") ==string("great-grandfather"));
    CHECK( T.relation("Orna") ==string("great-great-grandmother"));
    CHECK( T.relation("Roban") ==string("great-great-grandfather"));
       CHECK_THROWS(T.addFather("Benni", "itay")); //Benni is not in the family tree
    CHECK_THROWS(T.addFather("Yosef", "Yaakov")); //Yosef has a father already
    CHECK( T.relation("Yaakov") ==string("father"));
    CHECK( T.relation("Rachel") ==string("mother"));
    CHECK( T.relation("Isaac") ==string("grandfather"));
    CHECK( T.relation("Rivka") ==string("grandmother"));
    CHECK( T.relation("Avraham") ==string("great-grandfather"));
    CHECK( T.relation("Sarah") ==string("great-grandmother"));
    CHECK( T.relation("Terah") ==string("great-great-grandfather"));
    CHECK(T.relation("Yosef")==string("me"));
    CHECK( T.relation("Bella") ==string("great-great-grandmother"));
    CHECK( T.relation("Alex") ==string("great-great-great-grandfather"));
    CHECK( T.relation("Dani") ==string("grandfather"));
    CHECK( T.relation("Tami") ==string("grandmother"));
    CHECK( T.relation("Roze") ==string("great-grandmother"));
    CHECK( T.relation("Yosi") ==string("great-grandfather"));
    CHECK( T.relation("Orna") ==string("great-great-grandmother"));
    CHECK( T.relation("Roban") ==string("great-great-grandfather"));
       CHECK_THROWS(T.addFather("Benni", "itay")); //Benni is not in the family tree
    CHECK_THROWS(T.addFather("Yosef", "Yaakov")); //Yosef has a father already
    CHECK( T.relation("Yaakov") ==string("father"));
    CHECK( T.relation("Rachel") ==string("mother"));
    CHECK( T.relation("Isaac") ==string("grandfather"));
    CHECK( T.relation("Rivka") ==string("grandmother"));
    CHECK( T.relation("Avraham") ==string("great-grandfather"));
    CHECK( T.relation("Sarah") ==string("great-grandmother"));
    CHECK( T.relation("Terah") ==string("great-great-grandfather"));
    CHECK(T.relation("Yosef")==string("me"));
    CHECK( T.relation("Bella") ==string("great-great-grandmother"));
    CHECK( T.relation("Alex") ==string("great-great-great-grandfather"));
    CHECK( T.relation("Dani") ==string("grandfather"));
    CHECK( T.relation("Tami") ==string("grandmother"));
    CHECK( T.relation("Roze") ==string("great-grandmother"));
    CHECK( T.relation("Yosi") ==string("great-grandfather"));
    CHECK( T.relation("Orna") ==string("great-great-grandmother"));
    CHECK( T.relation("Roban") ==string("great-great-grandfather"));
}
