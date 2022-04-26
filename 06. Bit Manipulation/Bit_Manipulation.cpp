/*

BitManipulation

    - Get ith bit
    - Clear ith bit
    - Set ith bit
    - Update ith bit
    - Clear last m bits
    - Toggle last m bits
    - Clear range of bits (i to j)
    - Replace range of bits (i to j) with a binary number m
    - Check if power of 2
    - Count number of bits version 1
    - Count number of bits version 2
    - Convert to Binary

*/

class BitManipulation
{
private:
    int n;

public:
    BitManipulation(int x)
    {
        n = x;
    }

    // Get ith bit
    int getBit(int);

    // Clear ith bit
    void clearBit(int);

    // Set ith bit
    void setBit(int);

    // Update ith bit
    void updateBit(int, int);

    // Clear last m bits
    void clearLastBits(int);

    // Toggle last m bits
    void toggleLastBits(int);

    // Clear range of bits (i to j)
    void clearRangeOfBits(int, int);

    // Replace range of bits (i to j) with a binary number m
    void replaceRangeOfBits(int, int, int);

    // Check if power of 2
    bool isPowerOf2();

    // Count number of bits version 1
    int countBits();

    // Count number of bits version 2
    int countBitsV2();

    // Convert to Binary
    int convertToBinary();
};

int BitManipulation::getBit(int i)
{
    return ((n & (1 << i)) >> i);
}

void BitManipulation::clearBit(int i)
{
    n = n & (~(1 << i));
}

void BitManipulation::setBit(int i)
{
    n = n | (1 << i);
}

void BitManipulation::updateBit(int i, int b)
{
    clearBit(i);

    int mask = (b << i);
    n = n | mask;
}

void BitManipulation::clearLastBits(int m)
{
    int mask = (-1 << m);
    n = n & mask;
}

void BitManipulation::toggleLastBits(int m)
{
    int mask = (1 << m) - 1;
    n = n ^ mask;
}

void BitManipulation::clearRangeOfBits(int i, int j)
{
    int x = (-1 << (i + 1));
    int y = (1 << j) - 1;

    int mask = x | y;
    n = n & mask;
}

void BitManipulation::replaceRangeOfBits(int m, int i, int j)
{
    clearRangeOfBits(i, j);

    int mask = (m << j);
    n = n | mask;
}

bool BitManipulation::isPowerOf2()
{
    if (n & (n - 1) == 0)
        return true;
    else
        return false;
}

int BitManipulation::countBits()
{
    int count = 0;
    int temp = n;

    while (temp > 0)
    {
        int lastBit = (temp & 1);
        count += lastBit;
        temp = temp >> 1;
    }

    return count;
}

int BitManipulation::countBitsV2()
{
    int count = 0;
    int temp = n;

    while (temp > 0)
    {
        temp = temp & (temp - 1);
        count++;
    }

    return count;
}

int BitManipulation::convertToBinary()
{
    int ans = 0;
    int cnt = 1;
    int temp = n;

    while (temp > 0)
    {
        int lastBit = (temp & 1);
        ans += cnt * lastBit;
        cnt *= 10;
        temp = temp >> 1;
    }

    return ans;
}
