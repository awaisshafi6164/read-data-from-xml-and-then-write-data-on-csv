#include <iostream>
#include "pugixml.cpp"
#include <vector>
#include <fstream>

using namespace std;
using namespace pugi;

int main()
{

    vector<string> vec;

    vec.push_back("Customer");
    vec.push_back("Product");
    vec.push_back("Q tr_1");

    cout<<"\t\t===== XML READER =====\n\n";

    xml_document doc;

    if (!doc.load_file("Student.xml")){
        cout<<"File Did not open.\n";
        return 0;
    }
    cout << "\nParsing Data From File\n\n";
    xml_node skip = doc.child("root").child("Source_Data");
x:
    xml_node sam = skip;
    xml_node fName = sam.child( "Customer" );
    xml_node sName = sam.child( "Product" );
    xml_node tName = sam.child( "Qtr_1" );

    int i = 0;
    for (xml_node_iterator it = skip.begin(); it != skip.end(); ++it)
    {

        for (xml_attribute_iterator ait = it->attributes_begin(); ait != it->attributes_end(); ++ait)
        {
            cout << ait->name() << " = " << ait->value() << "\n";
        }

        if( i == 0){
            cout<< "Product = " <<sName.text().get()<<endl;
            vec.push_back(sName.text().get());
            cout<< "Customer = " <<fName.text().get()<<endl;
            vec.push_back(fName.text().get());
            cout<< "Qtr_1 = " <<tName.text().get()<<endl;
            vec.push_back(tName.text().get());
            cout<<"======================================="<<endl;
            i++;
        }
    }

    if(skip.next_sibling() != NULL){
        skip = skip.next_sibling();
        goto x;
    }
    cout<<"============================================\n";
    cout<<"============================================\n";
    cout<<"============================================\n\n\n";

    system("pause");

    for(unsigned int i = 0;i<vec.size();i++){
        cout<<vec[i]<<"\t";
        i++;
        cout<<vec[i]<<"        ";
        i++;
        cout<<vec[i]<<endl;
    }

    cout<<"The Size of vec = "<<vec.size();


    ofstream myFile("student.csv");

    myFile << "Student Record\n";
    for(unsigned int i = 0; i < vec.size(); i++){
        myFile << vec[i]<< ", ";
        i++;
        myFile<< vec[i]<< ", ";
        i++;
        myFile<< vec[i]<< "\n";
    }

    myFile.close();

    return 0;

}
