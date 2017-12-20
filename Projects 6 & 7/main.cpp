//
//  Maksim Nedorezov
//  CISP 400 - MW 3:00pm
//  Project 6
//  April 27, 2016
//

#include "ExpandArray.h"

using namespace std;

int main()
{
    int ints[5] = { 1, 5, 2, 76, 4393 };

    ExpandArray<int> array1;
    cout << "Array 1\n" << array1 << endl;

    ExpandArray<int> array2(10, 0);
    cout << "Array 2\n" << array2 << endl;

    ExpandArray<int> array3(ints, 5, -4, 1);
    cout << "Array 3\n" << array3 << endl;

    ExpandArray<int> array4(array3);
    cout << "Array 4\n" << array4 << endl;

    {
        ExpandArray<float> array5;
        ExpandArray<float> array6;
        array6.append(56.3464);
        cout << "Array 6\n" << array6 << endl;

        array5.write("array5");
        array6.write("array6");
    }

    ExpandArray<int> array7(56, 0.25);
    array7 = array4;
    cout << "Array 7\n" << array7 << endl;

    array7.write("array7");

    ExpandArray<float> *array8 = new ExpandArray<float>(48, 0.78);
    array8->append(3829.2098352);
    cout << "Array 8\n" << array8 << endl;

    array3[-4] = 202891;
    cout << "array3[-4] = " << array3[-4] << endl;

    const ExpandArray<float> array9(*array8);

    delete array8;

    cout << "Array 9\n" << array9 << endl;
    cout << "array9[48] = " << array9[48] << endl << endl;

    try {
        cout << "Array 3\n" << array3 << endl;
        cout << "array3(-3, 0)\n" << array3(-4, -2) << endl;
        cout << "Array 3\n" << array3 << endl;
    } catch (IOOR exception) {
        cout << exception << endl;
    }

    for (int i = 29; i < 69; i++)
        array3.append(i);

    cout << "Array 3\n" << array3 << endl;

    array7.append(array3);
    cout << "Array 7\n" << array7 << endl;

    cout << "array3.size()\n" << array3.size() << endl;

    array3.remove(23);
    array3.remove(-4);
    cout << "Array 3\n" << array3 << endl;

    try {
        array3.remove(38);
    } catch (IOOR exception) {
        cout << exception << endl;
    }

    cout << "Array 3\n" << array3 << endl;

    try {
        for (int i = 0; i < 50; i++)
            array3.remove();
    } catch (IOOR exception) {
        cout << exception << endl;
    }

    cout << "Array 3\n" << array3 << endl;

    try {
        array3.append(48);
        array3.insert(59);
    } catch (IOOR exception) {
        cout << exception << endl;
    }

    cout << "Array 3\n" << array3 << endl;

    ExpandArray<int> array10;
    array10.read("array7");
    cout << "Array 10\n" << array10 << endl;

    ExpandArray<float> array11;
    array11.read("array6");
    cout << "Array 11\n" << array11 << endl;

    array11.read("array5");
    cout << "Array 11\n" << array11 << endl;

    char text[21] = "Happy Birthday baby!";

    ExpandArray<char> array12(text, 20, 5, 1);
    cout << "Array 12\n" << array12 << endl;

    ExpandArray<char> array13;
    array12.append(array13);
    array12.append('A');

    cout << "Array 12\n" << array12 << endl;

    return 0;
}
