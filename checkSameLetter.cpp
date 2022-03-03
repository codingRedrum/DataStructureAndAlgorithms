#include <iostream>

constexpr const char arrayCompileTime[] = "Adrian";

template <typename T, std::size_t N>
constexpr std::size_t arraySize(T (&array)[N]) noexcept
{
    return N;
}

template <typename T, std::size_t N>
constexpr bool checkSameLetter(T (&array)[N]) noexcept
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
                        return true;
            }
        }
    }
       return false;
}

int 
main(int argc, char** argv)
{
    const bool result = checkSameLetter(arrayCompileTime);
    std::cout << result << std::endl;

    return 0;
}
