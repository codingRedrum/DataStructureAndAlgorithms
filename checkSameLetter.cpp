#include <iostream>

constexpr const char arrayCompileTime[] = "Adrian";

template <typename T, std::size_t N>
constexpr std::size_t arraySize(T (&array)[N]) noexcept
{
    return N;
}

template <typename T, std::size_t N>
constexpr const char* checkSameLetter(T (&array)[N]) noexcept
{
    constexpr std::size_t arrSize { arraySize(array) };

    for (std::size_t i {0}; i < arrSize-1; i++)
    {
        int val {0};
        for (std::size_t j {0}; j < arrSize-1; j++)
        {
            if (array[i] == array[j])
            {
                val++;
                    if (val == 2)
                        return "Word has min 2 same letters \n";
            }
        }
    }
       return "Word does not have same letter \n";
}

int 
main(int argc, char** argv)
{
    printf("%s \n", checkSameLetter(arrayCompileTime));

    return 0;
}
