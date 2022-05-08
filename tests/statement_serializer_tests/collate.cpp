#include <sqlite_orm/sqlite_orm.h>
#include <catch2/catch.hpp>

using namespace sqlite_orm;

TEST_CASE("statement_serializer collate") {
    internal::storage_impl<> storage;
    internal::serializer_context<internal::storage_impl<>> context{storage};
    {
        auto col = collate_nocase();
        auto value = serialize(col, context);
        REQUIRE(value == "COLLATE NOCASE");
    }
    {
        auto col = collate_binary();
        auto value = serialize(col, context);
        REQUIRE(value == "COLLATE BINARY");
    }
    {
        auto col = collate_rtrim();
        auto value = serialize(col, context);
        REQUIRE(value == "COLLATE RTRIM");
    }
}