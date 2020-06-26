/* See ../LICENSE for license details. */

void
insertionSort(unsigned int buff[], unsigned const int size)
{
    assert(buff);
    unsigned int i = 1;

    while(i < size) {
        unsigned int j = i;

        while(j > 0 && buff[j-1] > buff[j]) {
            swap(buff[j], buff[j-1]);
            j--;
        }
        i++;
    }
}
