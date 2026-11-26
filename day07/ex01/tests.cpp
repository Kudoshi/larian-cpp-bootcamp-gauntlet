// tests.cpp: no main(), no #define. catch_amalgamated.cpp supplies the runner
#include "catch_amalgamated.hpp"
#include "Inventory.hpp"

struct InventoryFixture
{
    Inventory inventory;

    InventoryFixture()
    {
        inventory.add("potion");
        inventory.add("sword");
    }
};

TEST_CASE_METHOD(InventoryFixture, "Adding an item raises a count")
{
    inventory.add("item_1");

    REQUIRE(inventory.count() == 3);
}

TEST_CASE_METHOD(InventoryFixture, "Find an added item and rejects a missing one")
{
    CHECK(inventory.has("potion"));

    REQUIRE(inventory.has("elixir") == false);
}

TEST_CASE_METHOD(InventoryFixture, "Removing an item dropping the count and has() stops finding it")
{
    int bfrCount = inventory.count();

    inventory.remove("potion");

    CHECK(inventory.count() == bfrCount - 1);
    CHECK_FALSE(inventory.has("potion"));
}


TEST_CASE_METHOD(InventoryFixture, "Remove missing item")
{
    int bfrCount = inventory.count();

    inventory.remove("elixir");

    CHECK(inventory.count() == bfrCount);
    CHECK(inventory.has("potion"));
}