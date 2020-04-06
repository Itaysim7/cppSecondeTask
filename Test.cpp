/**
*AUTHORS: <Itay Simhayev 205666407>
 * Date: 2020-04
 */
#include "doctest.h"
#include "FamilyTree.hpp"
#include <string>

using namespace std;
using namespace family;


TEST_CASE("Test Tree 1")
{
    family::Tree T ("Yosef"); // Yosef is the "root" of the tree (the youngest person).
	T.addFather("Yosef", "Yaakov")   
	 .addMother("Yosef", "Rachel")   
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
	 .addFather("Roze", "Roban")
	 .addMother("Orna", "Amit");
    CHECK_THROWS(T.addFather("Benni", "itay")); //Benni is not in the family tree
    CHECK_THROWS(T.addFather("Yosef", "Yaakov")); //Yosef has a father already
    CHECK( T.relation("Yaakov") ==string("father"));
    CHECK( T.relation("Rachel") ==string("mother"));
    CHECK( T.relation("Isaac") ==string("grandfather"));
    CHECK( T.relation("hani") ==string("unrelated"));
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
    CHECK( T.relation("Amit") ==string("great-great-great-grandmother"));

    //test find function
    CHECK(T.find("mother")==string("Rachel"));
    CHECK(T.find("father")==string("Yaakov"));
    CHECK(((T.find("grandmother")==string("Rivka"))||T.find("grandmother")==string("Tami")));
    CHECK(((T.find("grandfather")==string("Isaac"))||T.find("grandfather")==string("Dani")));
    CHECK(T.find("me")==string("Yosef")); 
    CHECK(((T.find("great-grandmother")==string("Sarah"))||T.find("great-grandmother")==string("Roze")));
    CHECK(((T.find("great-grandfather")==string("Avraham"))||T.find("great-grandfather")==string("Yosi")));
    CHECK(((T.find("great-great-grandfather")==string("Terah"))||T.find("great-great-grandfather")==string("Roban")));
    CHECK(((T.find("great-great-grandmother")==string("Bella"))||T.find("great-great-grandmother")==string("Orna")));
    CHECK(T.find("great-great-great-grandfather")==string("Alex"));
    CHECK(T.find("great-great-great-grandmother")==string("Amit"));
    T.remove("Alex");
    CHECK_THROWS(T.find("great-great-great-grandfather"));
    CHECK( T.relation("Alex") ==string("unrelated"));
    CHECK(((T.find("great-great-grandmother")==string("Bella"))||T.find("great-great-grandmother")==string("Orna")));
    CHECK( T.relation("Bella") ==string("great-great-grandmother"));
	T.addFather("Bella", "Alex");
    CHECK(T.find("great-great-great-grandfather")==string("Alex"));
    CHECK( T.relation("Alex") ==string("great-great-great-grandfather"));
    T.addFather("Orna", "Itan");
    CHECK( T.relation("Itan") ==string("great-great-great-grandfather"));
    T.addMother("Itan", "Yasmin");
    CHECK( T.relation("Yasmin") ==string("great-great-great-great-grandmother"));
    T.addFather("Itan", "Itamar");
    CHECK( T.relation("Itamar") ==string("great-great-great-great-grandfather"));
    T.remove("Orna");//remove orna itan yasmin itamar amit
    CHECK( T.relation("Orna") ==string("unrelated"));
    CHECK( T.relation("Itan") ==string("unrelated"));
    CHECK( T.relation("Yasmin") ==string("unrelated"));
    CHECK( T.relation("itamar") ==string("unrelated"));
    CHECK( T.relation("amit") ==string("unrelated"));
//check the other branch didnt damge

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
    CHECK( T.relation("Roban") ==string("great-great-grandfather"));
    T.remove("Rachel");//remove all the tree execpt yosef
    T.remove("Yaakov");//remove all the tree execpt yosef
   // check there is no any node any more
    CHECK( T.relation("Yaakov") ==string("unrelated"));
    CHECK( T.relation("Rachel") ==string("unrelated"));
    CHECK( T.relation("Isaac") ==string("unrelated"));
    CHECK( T.relation("Rivka") ==string("unrelated"));
    CHECK( T.relation("Avraham") ==string("unrelated"));
    CHECK( T.relation("Sarah") ==string("unrelated"));
    CHECK( T.relation("Terah") ==string("unrelated"));
    CHECK(T.relation("Yosef")==string("me"));
    CHECK( T.relation("Bella") ==string("unrelated"));
    CHECK( T.relation("Alex") ==string("unrelated"));
    CHECK( T.relation("Dani") ==string("unrelated"));
    CHECK( T.relation("Tami") ==string("unrelated"));
    CHECK( T.relation("Roze") ==string("unrelated"));
    CHECK( T.relation("Yosi") ==string("unrelated"));
    CHECK( T.relation("Roban") ==string("unrelated"));
}
TEST_CASE("Test Tree 1")
{
    family::Tree T1 ("Itay"); // Yosef is the "root" of the tree (the youngest person).
	T1.addFather("Itay", "Alex")   
	 .addMother("Itay", "Bella")   
	 .addFather("Bella", "Roban")
	 .addMother("Bella", "Orna")
	 .addFather("Alex", "Ori")
     .addMother("Alex", "Sarah")
	 .addFather("Sarah", "Yaron")
	 .addMother("Yaron", "Michal")
	 .addFather("Michal", "Dani")
	 .addFather("Dani", "Yosi");
    CHECK_THROWS(T1.addFather("haim", "itay")); //haim is not in the family tree
    CHECK_THROWS(T1.addFather("Itay", "Yaakov")); //Itay has a father already
    CHECK( T1.relation("Alex") ==string("father"));
    CHECK( T1.relation("Bella") ==string("mother"));
    CHECK( T1.relation("Roban") ==string("grandfather"));
    CHECK( T1.relation("Ori") ==string("grandfather"));
    CHECK( T1.relation("Tiki") ==string("unrelated"));
    CHECK( T1.relation("Sarah") ==string("grandmother"));
    CHECK( T1.relation("Orna") ==string("grandmother"));
    CHECK( T1.relation("Yaron") ==string("great-grandfather"));
    CHECK( T1.relation("Michal") ==string("great-great-grandmother"));
    CHECK( T1.relation("Dani") ==string("great-great-great-grandfather"));
    CHECK(T1.relation("Yosi")==string("great-great-great-great-grandfather"));
    CHECK( T1.relation("Itay") ==string("me"));
    T1.remove("Alex");
    T1.remove("Bella");
    CHECK( T1.relation("Alex") ==string("unrelated"));
    CHECK( T1.relation("Bella") ==string("unrelated"));
    CHECK( T1.relation("Roban") ==string("unrelated"));
    CHECK( T1.relation("Ori") ==string("unrelated"));
    CHECK( T1.relation("Sarah") ==string("unrelated"));
    CHECK( T1.relation("Orna") ==string("unrelated"));
    CHECK( T1.relation("Yaron") ==string("unrelated"));
    CHECK( T1.relation("Michal") ==string("unrelated"));
    CHECK( T1.relation("Dani") ==string("unrelated"));
    CHECK(T1.relation("Yosi")==string("unrelated"));
    CHECK( T1.relation("Itay") ==string("me"));

}