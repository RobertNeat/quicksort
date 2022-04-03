#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

struct students
{
    string name;
    string surname;
    int points;
};
//////////////////////////////////////////////////////////////////////////
int partAsc(students* arr,int start, int stop){

    int pivot=arr[stop].points;
    int i=(start-1);

    for(int j=start;j<=stop-1;j++){
        if(arr[j].points<=pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[stop]);
    return(i+1);
}
///////////////////////////////////////////////////////////////////////////
int partDesc(students* arr,int start, int stop){

    int pivot=arr[stop].points;
    int i=(start-1);

    for(int j=start;j<=stop-1;j++){
        if(arr[j].points>=pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[stop]);
    return(i+1);
}

///////////////////////////////////////////////////////////////////////////

void quickSort(students* arr,int start,int stop, int n, int mode)
{
if(mode==0){    //ascending sorting by points
    if(start<stop){
        int piv=partAsc(arr,start,stop);
        quickSort(arr,start,piv-1,n,mode);
        quickSort(arr,piv+1,stop,n,mode);
    }
}
else if(mode==1){   //descending sorting by points
    if(start<stop){
        int piv=partDesc(arr,start,stop);
        quickSort(arr,start,piv-1,n,mode);
        quickSort(arr,piv+1,stop,n,mode);
    }
}
//arr[i].points
}

//////////////////////////////////////////////////////////////////////////////
void readStudents(students*& arr, int studentCount, ifstream& file)
{
    string line, help;
    char semicolons;
    for (int i = 0;i < 2;i++)
    {
        file >> semicolons;
    }
    for (int i = 0;i < studentCount;i++)
    {
        file >> line;
        istringstream ss(line);
        getline(ss, arr[i].name, ';');
        getline(ss, arr[i].surname, ';');
        getline(ss, help);
        arr[i].points = atoi(help.c_str());
    }
}
void displayStudents(students* arr, int studentCount)
{
    for (int i = 0;i < studentCount;i++)
    {
        cout <<"name: " <<arr[i].name <<" \tsurname: "<<arr[i].surname<<" \tpoints: "<<arr[i].points<< endl;
    }
}
int main()
{
    int studentCount;
    students* arr;
    ifstream file;
    file.open("students.csv");
    file >> studentCount;
    arr=new students[studentCount];
    readStudents(arr, studentCount, file);

    cout<<endl<<"Choose how should be the records sorted (0-ascending, 1-descending):";
    int a;
    cin>>a;
    quickSort(arr,0,studentCount-1,studentCount,a);

    //cout<<endl;

    displayStudents(arr, studentCount);
    delete[] arr;
    file.close();
}
