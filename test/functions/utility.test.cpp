#include "functions/utility.hpp"

#include <string>

#include "third_party/catch.hpp"

TEST_CASE("Convert to Base64 from String", "[utility][convert][string]") {
    std::string num = "481482486096808911670147153572883801";
    // Magnitude should be {11670147153572883801, 4814824860968089}
    auto magnitude = convert_to_base_64(num);
    REQUIRE(magnitude.size() == 2);
    REQUIRE(magnitude[0] == uint64_t(11670147153572883801));
    REQUIRE(magnitude[1] == uint64_t(4814824860968089));

    num = "1";
    magnitude = convert_to_base_64(num);
    REQUIRE(magnitude.size() == 1);
    REQUIRE(magnitude[0] == 1);

    num = "";
    magnitude = convert_to_base_64(num);
    REQUIRE(magnitude.size() == 1);
    REQUIRE(magnitude[0] == 0);
}