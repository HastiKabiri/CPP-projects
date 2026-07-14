// Hasti Kabiri - TP085940
// lab exercise 3



#include <iostream>
#include <string>

using namespace std;





// QUESTION 1

struct Student {
    string name;
    int studentID;
    float grades[5];

    Student(string n, int id, float g1, float g2, float g3, float g4, float g5) {
        name = n;
        studentID = id;
        grades[0] = g1; grades[1] = g2; grades[2] = g3; grades[3] = g4; grades[4] = g5;
    }
    
    // یک سازنده پیش‌فرض هم نیاز داریم برای آرایه
    Student() {} 
};

float calculateAverage(Student s) {
    float sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += s.grades[i];
    }
    return sum / 5.0;
}












// QUESTION 5

class Classroom {
private:
    int* scores;
    int size;

// * for pointer (stores a memory address)

public:
    Classroom(int s) {
        size = s;
        scores = new int[size];
    }

    Classroom(const Classroom &obj) {
        size = obj.size;
        scores = new int[size];
        for (int i = 0; i < size; i++) {
            scores[i] = obj.scores[i];
        }
    }

    ~Classroom() {
        delete[] scores;
    }

    void setScore(int index, int score) {
        if (index >= 0 && index < size) {
            scores[index] = score;
        }
    }

    int getHighest() {
        int high = scores[0];
        for (int i = 1; i < size; i++) {
            if (scores[i] > high) high = scores[i];
        }
        return high;
    }
};






int main() {
    // --- QUESTION 1 ---
    cout << "--- Question 1: Student Structs ---" << endl;
    Student stList[3] = {
        Student("Hasti", 101, 85, 90, 78, 92, 88),
        Student("Maryam", 102, 70, 65, 80, 72, 68),
        Student("Ehtisham", 103, 95, 98, 92, 94, 97)
    };

    for (int i = 0; i < 3; i++) {
        cout << "Name: " << stList[i].name << " | Average: " << calculateAverage(stList[i]) << endl;
    }
    cout << endl;









    // --- QUESTION 4 ---
    cout << "--- Question 4: Dynamic Array ---" << endl;
    int n;
    cout << "Enter array size: ";
    cin >> n;

    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter value " << i + 1 << ": ";
        cin >> arr[i];
    }

    int max = arr[0], min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) max = arr[i];
        if (arr[i] < min) min = arr[i];
    }

    cout << "Max: " << max << " | Min: " << min << endl;
    delete[] arr; 
    cout << endl;








    // --- QUESTION 5 ---
    cout << "--- Question 5: Classroom Class ---" << endl;
    Classroom myClass(5);
    int sampleScores[] = {88, 92, 76, 99, 84};
    
    for(int i = 0; i < 5; i++) {
        myClass.setScore(i, sampleScores[i]);
    }

    cout << "Highest Score: " << myClass.getHighest() << endl;

    return 0;
}