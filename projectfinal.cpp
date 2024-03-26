#include<iostream>
#include<string>
#include<fstream>
#include <Windows.h>

#ifdef _WIN32
    #define CLEAR_SCREEN "cls"
#else
    #define CLEAR_SCREEN "clear"
#endif


using namespace std;
struct Patient {
    string name;
    string appointmentTime;
    int age;
    int appointmentNo;
};
struct Staff {
    string name;
    int age;
    int salary;
    string position;
};

void PatientInfo(string doc);
void appoitmentfiling(string doc,Patient patient);
void Display_appointmentread(string doc);
void DocInformation();
void DocAppointment();
void StaffInfo();
void Display_Appoint();
void display_staffinfo();
void display_authorize();
void Check_Condition();


void Menu(){
    int choice;
    cout<<"____________________________________________________________________________________________________________________________________________________________________________"<<endl;
    cout<<"                                                  Please select any option                                            "<<endl;
    cout<<"                                                                                                                        "<<endl;
    cout<<"                                                                                                                        "<<endl;
    cout<<"1-     Press 1 for available of doctor information                                                                     "<<endl;
    cout<<"2-     Press 2 for doctor appointiment                                                                                 "<<endl;
    cout<<"3-     Press 3 for saving staff information                                                                            "<<endl;
    cout<<"4-     Press 4 for checking patient appoitment menu                                                                    "<<endl;
    cout<<"5-     Press 5 for checking staff information                                                                          "<<endl;
    cout<<"6-     Press 6 for Authorized user of Hospital Management system                                                                                              "<<endl;

    cout<<"7-     Press 7 for logout                                                                                              "<<endl;
    cout<<"                                                                                                                         "<<endl;
    cout<<"                                                                                                                         "<<endl;
    cout<<"____________________________________________________________________________________________________________________________________________________________________________"<<endl;
    cout<<"                                                                        Enter choice: ";
    cin>>choice;
    switch(choice){
    case 1:
        system(CLEAR_SCREEN);
        DocInformation();//1
    break;
    case 2: system(CLEAR_SCREEN);
        DocAppointment(); //2
    break;
    case 3:system(CLEAR_SCREEN);
        StaffInfo();//3
    break;
    case 4: system(CLEAR_SCREEN);
        Display_Appoint(); //4
    break;
    case 5: system(CLEAR_SCREEN);
     display_staffinfo();//5
    break;
    case 6: system(CLEAR_SCREEN);
        display_authorize();
    break;
    case 7:
        system(CLEAR_SCREEN);
    Check_Condition();
        }

}
void DocInformation(){ //1

        cout<<"                                                                                                                        "<<endl;
        cout<<"                                                                                                                        "<<endl;
        cout<<"                                                                                                                        "<<endl;

        cout<<"                                               <THREE DOCTORS AVAILIABLE>                                                             "<<endl;
        cout<<"                                      [Information and Timings are given below]                                                        "<<endl;
        cout<<"                                                                                                                        "<<endl;
        cout<<"____________________________________________________________________________________________________________________________________________________________________________"<<endl;
        cout<<"                                      Dr.Abdul Haleem Mirani<Eye Surgeon>                                                                                            "<<endl;
        cout<<"                                               [Timing]                                                                                          "<<endl;
        cout<<"                                 Monday to Friday    9AM to 5pm                                                                                              "<<endl;
        cout<<"                                 Saturday            9AM to 1pm                                                                                                       "<<endl;
        cout<<"                                 Sunday              OFF                                                                                         "<<endl;
        cout<<"____________________________________________________________________________________________________________________________________________________________________________"<<endl;


        cout<<"                                                                                                                        "<<endl;
        cout<<"____________________________________________________________________________________________________________________________________________________________________________"<<endl;
        cout<<"                                      Dr.Ajeet Makhija<Child Specialist>                                                                                            "<<endl;
        cout<<"                                               [Timing]                                                                                          "<<endl;
        cout<<"                                 Monday to Friday    9AM to 2pm                                                                                             "<<endl;
        cout<<"                                 Saturday            9AM to 12pm                                                                                                       "<<endl;
        cout<<"                                 Sunday              OFF                                                                                         "<<endl;
        cout<<"____________________________________________________________________________________________________________________________________________________________________________"<<endl;

        cout<<"                                                                                                                        "<<endl;
        cout<<"____________________________________________________________________________________________________________________________________________________________________________"<<endl;
        cout<<"                                      Dr.Rohit Kumar<Cardiologist>                                                                                            "<<endl;
        cout<<"                                               [Timing]                                                                                          "<<endl;
        cout<<"                                 Monday to Friday    1pm to 8pm                                                                                              "<<endl;
        cout<<"                                 Saturday            0FF                                                                                                       "<<endl;
        cout<<"                                 Sunday              OFF                                                                                         "<<endl;
        cout<<"____________________________________________________________________________________________________________________________________________________________________________"<<endl;
        cout<<"Press the Shift key to return into the menu"<<endl;
      while(true){
    if (GetAsyncKeyState(VK_SHIFT) & 0x8000) {
            // If Shift key is pressed, end the while loop
            // and call Menu()
                        system(CLEAR_SCREEN);
            Menu();
        }
      }
}
void DocAppointment(){ // print the aviable doctors in the hospital
    int choice1;
        cout<<"                                                                                                                       "<<endl;
        cout<<"   Press 1 for Dr.Abdul Haleem Mirani                                                                                                                   "<<endl;
        cout<<"   Press 2 for Dr.Ajeet Makhija                                                                                                                     "<<endl;
        cout<<"   Press 3 for Dr.Rohit Kumar                                                                                                                     "<<endl;
        cout<<"                                                                                                                        "<<endl;
cout<<"Choose your doctor: ";
cin>>choice1;
switch(choice1){
case 1:
    PatientInfo("Haleem");
    break;
case 2:
    PatientInfo("Ajeet");
    break;
case 3:
    PatientInfo("Rohit");
    break;
}


}
void PatientInfo(string doc) // getting the info of patient
{
	Patient patient;
        cout<<"                                                                                                                        "<<endl;
        cout<<"                                                                                                                        "<<endl;


cout<<"Enter the patient name :";
cin>>patient.name;
cout<<"Enter the appointement time:";
cin>>patient.appointmentTime;
cout<<"Enter age of patient:";
cin>>patient.age;
cout<<"Enter appointment no:";
cin>>patient.appointmentNo;
appoitmentfiling(doc,patient);
cout<<"                                                                                                                        "<<endl;
         cout << "Press Shift Key to return to menu" << endl;
          while(true){
    if (GetAsyncKeyState(VK_SHIFT) & 0x8000) {
            // If Shift key is pressed, end the while loop
            // and call Menu()
                        system(CLEAR_SCREEN);
            Menu();
        }
      }

}
void StaffInfo(){ // getting staff info and create the file of staff and append the information of staff in the file
    Staff staff;
    cout<<"Enter name:";
    cin>>staff.name;
      cout<<"Enter working position:";
    cin>>staff.position;
      cout<<"Enter salary:";
    cin>>staff.salary;
      cout<<"Enter age:";
    cin>>staff.age;
    cout<<"Your information has been saved "<<endl;

    ofstream outputFile("Staff.txt", ios::app);


string dataToAppend =
       staff.name + "\n" +
        staff.position + "\n" +
        to_string(staff.salary) + "\n" +
        to_string(staff.age);

    // Append data to the file
    outputFile << dataToAppend<<endl;

    // Close the file
    outputFile.close();

    cout << "Data appended successfully!" << endl;
    cout << "Press Shift Key to return to menu" << endl;
          while(true){
    if (GetAsyncKeyState(VK_SHIFT) & 0x8000) {
            // If Shift key is pressed, end the while loop
            // and call Menu()
                        system(CLEAR_SCREEN);
            Menu();
        }
      }

}

void appoitmentfiling(string doc,Patient patient){ // Create and append in the doctor file
// Open the file in append mode
    ofstream outputFile(doc+".txt", ios::app);


string dataToAppend =
        patient.name + "\n" +
        patient.appointmentTime + "\n" +
        to_string(patient.age) + "\n" +
        to_string(patient.appointmentNo);

    // Append data to the file
    outputFile << dataToAppend<<endl;;

    // Close the file
    outputFile.close();

    cout << "Data appended successfully!" << endl;

}
void Display_Appoint(){
    int choice1;
        cout<<"                                                                                                                       "<<endl;
        cout<<"   Press 1 for Dr.Abdul Haleem Mirani                                                                                                                   "<<endl;
        cout<<"   Press 2 for Dr.Ajeet Makhija                                                                                                                     "<<endl;
        cout<<"   Press 3 for Dr.Rohit Kumar                                                                                                                     "<<endl;
        cout<<"                                                                                                                        "<<endl;
cout<<"Choose your doctor: ";
cin>>choice1;
switch(choice1){
case 1:
    Display_appointmentread("Haleem");
    break;
case 2:
    Display_appointmentread("Ajeet");
    break;
case 3:
		Display_appointmentread("Rohit");
    break;
}

    cout << "Press Shift Key to return to menu" << endl;
          while(true){
    if (GetAsyncKeyState(VK_SHIFT) & 0x8000) {
            // If Shift key is pressed, end the while loop
            // and call Menu()
                        system(CLEAR_SCREEN);
            Menu();
        }
      }


}
void Display_appointmentread(string doc){
	string myText;
	string arr[4];
	string info[]={"Name","Time","Age","No"};
    int count=0;
// Read from the text file
ifstream MyReadFile(doc+".txt");

// Use a while loop together with the getline() function to read the file line by line
while (getline (MyReadFile, myText)) {
  // Output the text from the file
  arr[count] = myText;
  cout << info[count]<<" : "<<arr[count]<<endl;
    count++;
  if(count == 4){
    count=0;
    cout<<endl;
  }
}

// Close the file
MyReadFile.close();

}
void display_staffinfo(){

	string myText;
	string arr[4];
	string info[]={"Name","Position","salary","Age"};
    int count=0;
// Read from the text file
ifstream MyReadFile("Staff.txt");

// Use a while loop together with the getline() function to read the file line by line
while (getline (MyReadFile, myText)) {
  // Output the text from the file
  arr[count] = myText;
  cout << info[count]<<" : "<<arr[count]<<endl;
    count++;
  if(count == 4){
    count=0;
    cout<<endl;
  }
}

// Close the file
MyReadFile.close();
    cout << "Press Shift Key to return to menu" << endl;
          while(true){
    if (GetAsyncKeyState(VK_SHIFT) & 0x8000) {
            // If Shift key is pressed, end the while loop
            // and call Menu()
                        system(CLEAR_SCREEN);
            Menu();
        }
      }


}
bool Auth_User(){
    string username,pass;
    cout<<"Enter the Username : ";
    cin>>username;
    cout<<"Enter the Password : ";
    cin>>pass;

    bool save;
    int count=0;
    string arr[2];
    string myText;
    // Read from the text file
ifstream MyReadFile("Authorizate.txt");

// Use a while loop together with the getline() function to read the file line by line
while (getline (MyReadFile, myText)) {
  // Output the text from the file
    arr[count++] = myText;
    if(count == 2){
        if(username == arr[0] && pass== arr[1]){
            save = true;
            break;
        }
        else{
            save = false;
            count=0;
        }
    }
}

// Close the file
MyReadFile.close();

    return save;

}

void display_authorize(){
    int count=0;
    string myText;
    string arr[2];
    // Read from the text file
ifstream MyReadFile("Authorizate.txt");

cout<<"Authorize Users that Access this system \n\n\n"<<endl;
// Use a while loop together with the getline() function to read the file line by line
while (getline (MyReadFile, myText)) {
  // Output the text from the file
            if(count==0){
            arr[count] = myText;
            cout<<"UserName : "<<arr[count]<<endl;
            }
            count++;
     if(count==2){
        count=0;
    }


}

// Close the file
MyReadFile.close();

    cout << "Press Shift Key to return to menu" << endl;
          while(true){
    if (GetAsyncKeyState(VK_SHIFT) & 0x8000) {
            // If Shift key is pressed, end the while loop
            // and call Menu()
                        system(CLEAR_SCREEN);
            Menu();
        }
      }

}
void Check_Condition(){
        if(Auth_User()){
         Menu();
      }
    else{
        cout<<"Wrong username or password, try again"<<endl;
    }

}


int main(){

Check_Condition();


}




