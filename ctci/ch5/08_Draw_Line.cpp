#include <iostream>
#include <vector>

class Question
{
public:
    static int computeByteNum(int width, int x, int y)
    {
        return (width * y + x) / 8;
    }

    static void drawLine(std::vector<unsigned char> &screen, int width, int x1, int x2, int y)
    {
        int start_offset = x1 % 8;
        int first_full_byte = x1 / 8;
        if (start_offset != 0)
        {
            first_full_byte++;
        }

        int end_offset = x2 % 8;
        int last_full_byte = x2 / 8;
        if (end_offset != 7)
        {
            last_full_byte--;
        }

        // Set full bytes
        for (int b = first_full_byte; b <= last_full_byte; b++)
        {
            screen[(width / 8) * y + b] = 0xFF;
        }

        unsigned char start_mask = (0xFF >> start_offset);
        unsigned char end_mask = ~(0xFF >> (end_offset + 1));

        // Set start and end of line
        if ((x1 / 8) == (x2 / 8))
        { // If x1 and x2 are in the same byte
            unsigned char mask = (start_mask & end_mask);
            screen[(width / 8) * y + (x1 / 8)] |= mask;
        }
        else
        {
            if (start_offset != 0)
            {
                int byte_number = (width / 8) * y + first_full_byte - 1;
                screen[byte_number] |= start_mask;
            }
            if (end_offset != 7)
            {
                int byte_number = (width / 8) * y + last_full_byte + 1;
                screen[byte_number] |= end_mask;
            }
        }
    }

    static void printByte(unsigned char b)
    {
        for (int i = 7; i >= 0; i--)
        {
            char c = ((b >> i) & 1) == 1 ? '1' : '_';
            std::cout << c;
        }
    }

    static void printScreen(const std::vector<unsigned char> &screen, int width)
    {
        int height = screen.size() * 8 / width;
        for (int r = 0; r < height; r++)
        {
            for (int c = 0; c < width; c += 8)
            {
                unsigned char b = screen[computeByteNum(width, c, r)];
                printByte(b);
            }
            std::cout << std::endl;
        }
    }
};

int main()
{
    int width = 8 * 1;
    int height = 1;
    for (int r = 0; r < height; r++)
    {
        for (int c1 = 0; c1 < width; c1++)
        {
            for (int c2 = c1; c2 < width; c2++)
            {
                std::vector<unsigned char> screen(width * height / 8, 0);

                std::cout << "row: " << r << ": " << c1 << " -> " << c2 << std::endl;
                Question::drawLine(screen, width, c1, c2, r);
                Question::printScreen(screen, width);
                std::cout << std::endl
                          << std::endl;
            }
        }
    }

    return 0;
}
