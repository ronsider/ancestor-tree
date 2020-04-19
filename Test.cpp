/*Date: April 2020
 *
 *
 * 
 *Ron Sider
 */


#include "doctest.h"
#include <iostream>

#include "FamilyTree.hpp"
using namespace family;
using namespace std;

//first family
TEST_CASE("check first group")
{
    family::Tree T1("didi");
    T1.addFather("didi", "avi")
        .addMother("didi", "linoy")

        .addFather("avi", "omri")
        .addMother("avi", "may")
        .addFather("linoy", "benny")
        .addMother("linoy", "shiran")

        .addFather("omri", "liran")
        .addMother("omri", "tali")
        .addFather("may", "shalom")
        .addMother("may", "shirley")
        .addFather("benny", "lidor")
        .addMother("benny", "olga")
        .addFather("shiran", "david")
        .addMother("shiran", "aviva")

        .addFather("liran", "chai")
        .addMother("liran", "netta")
        .addFather("tali", "yona")
        .addMother("tali", "yamit")
        .addFather("shalom", "nir")
        .addMother("shalom", "tzipi")
        .addFather("shirley", "yossi")
        .addMother("shirley", "shani")
        .addFather("lidor", "yaara")
        .addMother("lidor", "alina")
        .addFather("olga", "shimshon")
        .addMother("olga", "tammar")
        .addFather("david", "daniel")
        .addMother("david", "videl")
        .addFather("aviva", "shmulik")
        .addMother("aviva", "sapir");

    T1.display();

    CHECK(T1.relation("didi") == "me");
    CHECK(T1.relation("avi") == "father");
    CHECK(T1.relation("linoy") == "mother");

    CHECK(T1.relation("benny") == "grandfather");
    CHECK(T1.relation("shiran") == "grandmother");
    CHECK(T1.relation("omri") == "grandfather");
    CHECK(T1.relation("may") == "grandmother");

    CHECK(T1.relation("liran") == "great-grandfather");
    CHECK(T1.relation("tali") == "great-grandmother");
    CHECK(T1.relation("shalom") == "great-grandfather");
    CHECK(T1.relation("shirley") == "great-grandmother");
    CHECK(T1.relation("lidor") == "great-grandfather");
    CHECK(T1.relation("olga") == "great-grandmother");
    CHECK(T1.relation("david") == "great-grandfather");
    CHECK(T1.relation("aviva") == "great-grandmother");

    CHECK(T1.relation("chai") == "great-great-grandfather");
    CHECK(T1.relation("netta") == "great-great-grandmother");
    CHECK(T1.relation("yona") == "great-great-grandfather");
    CHECK(T1.relation("yamit") == "great-great-grandmother");
    CHECK(T1.relation("nir") == "great-great-grandfather");
    CHECK(T1.relation("tzipi") == "great-great-grandmother");
    CHECK(T1.relation("yossi") == "great-great-grandfather");
    CHECK(T1.relation("alina") == "great-great-grandmother");
    CHECK(T1.relation("yaara") == "great-great-grandfather");
    CHECK(T1.relation("alina") == "great-great-grandmother");
    CHECK(T1.relation("shimshon") == "great-great-grandfather");
    CHECK(T1.relation("tammar") == "great-great-grandmother");
    CHECK(T1.relation("daniel") == "great-great-grandfather");
    CHECK(T1.relation("videl") == "great-great-grandmother");
    CHECK(T1.relation("shmulik") == "great-great-grandfather");
    CHECK(T1.relation("sapir") == "great-great-grandmother");

    CHECK(T1.relation("jossef") == "unrelated");

    T1.remove("liran");
    CHECK(T1.relation("liran") == "unrelated");
    CHECK(T1.relation("chai") == "unrelated");
    CHECK(T1.relation("netta") == "unrelated");

    T1.remove("tali");
    CHECK(T1.relation("yona") == "unrelated");
    CHECK(T1.relation("yamit") == "unrelated");

    T1.remove("shalom");
    CHECK(T1.relation("nir") == "unrelated");
    CHECK(T1.relation("tzipi") == "unrelated");

    T1.remove("shirley");
    CHECK(T1.relation("yossi") == "unrelated");
    CHECK(T1.relation("shani") == "unrelated");

    T1.remove("lidor");
    CHECK(T1.relation("yaara") == "unrelated");
    CHECK(T1.relation("alina") == "unrelated");

    T1.remove("olga");
    CHECK(T1.relation("shimshon") == "unrelated");
    CHECK(T1.relation("tammar") == "unrelated");

    T1.remove("david");
    CHECK(T1.relation("daniel") == "unrelated");
    CHECK(T1.relation("videl") == "unrelated");

    T1.remove("aviva");
    CHECK(T1.relation("shmulik") == "unrelated");
    CHECK(T1.relation("sapir") == "unrelated");

    CHECK(T1.find("me") == "didi");
    CHECK(T1.find("mother") == "linoy");
    CHECK(T1.find("father") == "avi");
}
//second family
TEST_CASE("check second family")
{
    family::Tree T2("tal");
    T2.addFather("tal", "ziv")
        .addMother("tal", "liat")

        .addFather("liat", "menachem")
        .addMother("liat", "daniela")
        .addFather("ziv", "daniel")
        .addMother("ziv", "yifat")

        .addFather("menachem", "avihu")
        .addMother("menachem", "lihi")
        .addFather("daniela", "assaf")
        .addMother("daniela", "dorin")
        .addFather("daniel", "yagel")
        .addMother("daniel", "koral")
        .addFather("yifat", "noam")
        .addMother("yifat", "shlomi")

        .addFather("avihu", "alon")
        .addMother("avihu", "hilla")
        .addFather("lihi", "cedrick")
        .addMother("lihi", "limor")
        .addFather("assaf", "ofek")
        .addMother("assaf", "liora")
        .addFather("dorin", "ronel")
        .addMother("dorin", "priel")
        .addFather("yagel", "yoel")
        .addMother("yagel", "naama")
        .addFather("koral", "din")
        .addMother("koral", "ariella")
        .addFather("noam", "snir")
        .addMother("noam", "amit")
        .addFather("shlomi", "yehuda")
        .addMother("shlomi", "lin");

    T2.display();

    CHECK(T2.relation("tal") == "me");
    CHECK(T2.relation("ziv") == "father");
    CHECK(T2.relation("liat") == "mother");

    CHECK(T2.relation("menachem") == "grandfather");
    CHECK(T2.relation("daniela") == "grandmother");
    CHECK(T2.relation("daniel") == "grandfather");
    CHECK(T2.relation("yifat") == "grandmother");

    CHECK(T2.relation("avihu") == "great-grandfather");
    CHECK(T2.relation("lihi") == "great-grandmother");
    CHECK(T2.relation("assaf") == "great-grandfather");
    CHECK(T2.relation("dorin") == "great-grandmother");
    CHECK(T2.relation("yagel") == "great-grandfather");
    CHECK(T2.relation("koral") == "great-grandmother");
    CHECK(T2.relation("noam") == "great-grandfather");
    CHECK(T2.relation("shlomi") == "great-grandmother");

    CHECK(T2.relation("alon") == "great-great-grandfather");
    CHECK(T2.relation("hilla") == "great-great-grandmother");
    CHECK(T2.relation("cedrick") == "great-great-grandfather");
    CHECK(T2.relation("limor") == "great-great-grandmother");
    CHECK(T2.relation("ofek") == "great-great-grandfather");
    CHECK(T2.relation("liora") == "great-great-grandmother");
    CHECK(T2.relation("ronel") == "great-great-grandfather");
    CHECK(T2.relation("priel") == "great-great-grandmother");
    CHECK(T2.relation("yoel") == "great-great-grandfather");
    CHECK(T2.relation("naama") == "great-great-grandmother");
    CHECK(T2.relation("din") == "great-great-grandfather");
    CHECK(T2.relation("ariella") == "great-great-grandmother");
    CHECK(T2.relation("snir") == "great-great-grandfather");
    CHECK(T2.relation("amit") == "great-great-grandmother");
    CHECK(T2.relation("yehuda") == "great-great-grandfather");
    CHECK(T2.relation("lin") == "great-great-grandmother");

    CHECK(T2.relation("mendale") == "unrelated");

    T2.remove("shlomi");
    CHECK(T2.relation("shlomi") == "unrelated");
    CHECK(T2.relation("yehuda") == "unrelated");
    CHECK(T2.relation("lin") == "unrelated");

    T2.remove("avihu");
    CHECK(T2.relation("alon") == "unrelated");
    CHECK(T2.relation("hilla") == "unrelated");

    T2.remove("lihi");
    CHECK(T2.relation("cerdick") == "unrelated");
    CHECK(T2.relation("limor") == "unrelated");

    T2.remove("assaf");
    CHECK(T2.relation("ofek") == "unrelated");
    CHECK(T2.relation("liora") == "unrelated");

    T2.remove("dorin");
    CHECK(T2.relation("ronel") == "unrelated");
    CHECK(T2.relation("priel") == "unrelated");

    T2.remove("yagel");
    CHECK(T2.relation("yoel") == "unrelated");
    CHECK(T2.relation("naama") == "unrelated");

    T2.remove("koral");
    CHECK(T2.relation("din") == "unrelated");
    CHECK(T2.relation("ariella") == "unrelated");

    T2.remove("noam");
    CHECK(T2.relation("snir") == "unrelated");
    CHECK(T2.relation("amit") == "unrelated");

    CHECK(T2.find("me") == "tal");
    CHECK(T2.find("mother") == "liat");
    CHECK(T2.find("father") == "ziv");
}
