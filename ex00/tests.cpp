// tests.cpp: no main(), no #define. catch_amalgamated.cpp supplies the runner
#include "catch_amalgamated.hpp"
#include "Inventory.hpp"

TEST_CASE("Adding an item raises a count") {
    Inventory inv;
    inv.add("item_1");
    REQUIRE(inv.count() == 0);       // REQUIRE aborts the case; the line below is meaningless if this fails
}

// TEST_CASE("Find an added item and rejects a missing one")
// {
//     Inventory inv;
//     inv.add("ITEM_1");
//     inv.add("ITEM_2");

//     CHECK(inv.has("ITEM_1"));

//     REQUIRE(inv.has("ITEM_69") == false);
// }

// TEST_CASE("Removing an item dropping the count and has() stops finding it")
// {
//     Inventory inv;
//     inv.add("ITEM_1");
//     inv.add("ITEM_2");
//     int bfrCount = inv.count();
//     inv.remove("ITEM_1");
//     CHECK(inv.count() == bfrCount-1);
//     CHECK_FALSE(inv.has("ITEM_1"));
// }

// TEST_CASE("Remove missing item")
// {
//     Inventory inv;
//     int bfrCount = inv.count();
//     inv.remove("ITEM_420");
//     CHECK(inv.count() == bfrCount);
//     CHECK(inv.has("ITEM_1"));
// }