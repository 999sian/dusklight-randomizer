#include "../utility/endian.hpp"
#include <cassert>

int main() {
    using namespace Utility::Endian;
    const Type opposite = target == Type::Big ? Type::Little : Type::Big;
    // A swapped float can represent a NaN: compare its bits, not its numeric value.
    for (uint32_t bits : {0x00000000u, 0x80000000u, 0x3f800000u, 0x0000807fu, 0x7fc01234u}) {
        const float value = std::bit_cast<float>(bits);
        assert(std::bit_cast<uint32_t>(toPlatform(target, value)) == bits);
        assert(std::bit_cast<uint32_t>(toPlatform(opposite, value)) == byteswap(bits));
        float inplace = value;
        toPlatform_inplace(opposite, inplace);
        assert(std::bit_cast<uint32_t>(inplace) == byteswap(bits));
    }
    for (uint64_t bits : {uint64_t{0}, uint64_t{0x3ff0000000000000}, uint64_t{0x7ff8000000001234}}) {
        const double value = std::bit_cast<double>(bits);
        assert(std::bit_cast<uint64_t>(toPlatform(target, value)) == bits);
        assert(std::bit_cast<uint64_t>(toPlatform(opposite, value)) == byteswap(bits));
        double inplace = value;
        toPlatform_inplace(opposite, inplace);
        assert(std::bit_cast<uint64_t>(inplace) == byteswap(bits));
    }
    assert(toPlatform(opposite, uint32_t{0x12345678}) == 0x78563412u);
}
