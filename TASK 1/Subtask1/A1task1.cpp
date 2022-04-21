#include <iostream>
#include <vector>
#include<math.h>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

class Matrix_operations
{ public:  
vector<vector<float>>fully_connected_layer(vector<vector<float>>a,vector<vector<float>>weighted_matrix,vector<vector<float>>bias_matrix)
  { 
     
    if(a.at(0).size()!=weighted_matrix.size())
       { cout<<"Matrix Multiplication Not possible"<<endl;                //here checking wether the matrix operation is possible or not.
            exit(1);
       }
   vector<vector<float>>resultant_matrix;
    
    for(int i=0;i<a.size();i++)
        {    vector<float>temp;
              for(int j=0;j<weighted_matrix.at(0).size();j++)
                           {   float sum=0;
                                      for(int l=0;l<a.at(0).size();l++)                     //here calculating the inner product of inputmatrix a and weight matrix
                                      {      sum=sum+a[i][l]*weighted_matrix[l][j];

                                       }
                                   temp.push_back(sum);
                               }
                               
resultant_matrix.push_back(temp);
        }

for(int i=0;i<resultant_matrix.size();i++)
{
  for(int j=0;j<resultant_matrix.at(0).size();j++)
  resultant_matrix[i][j]=resultant_matrix[i][j]+bias_matrix[i][j];                    //adding the bias matrix to the matrix came out of multiplication of inputmatrix a and weight matrix
}

return resultant_matrix;                                         //finally returning the resultant matrix came from above two operations.

        }
       
          
      
vector<vector<float>>tanh_fn(vector<vector<float>>a)
{ for(int i=0;i<a.size();i++)
  {
         for(int j=0;j<a.at(0).size();j++)                              //as tanh fn is defined as (exp(2x)-1)/(exp(2x)+1) so here i replaced every elemeent of the vector according to the above defination and then finally returned the vector
         {
           a[i][j]=(exp(2*a[i][j])-1)/(exp(2*a[i][j])+1);
         }
}


return a;

}


vector<vector<float>>relu_fn(vector<vector<float>>a)
   { 
     for(int i=0;i<a.size();i++)                             //as relu fn is defined as max(0,x) so here also if the element is negative then i replaced that element with 0 and then finally returned the vector
       {  
           for(int j=0;j<a.at(i).size();j++)
               {    if(a.at(i).at(j)<0.0)
                     a[i][j]=0.0;
               }
}

return a;

   }



   vector<vector<float>>max_pooling(vector<vector<float>>a,int stride)
{ int row=a.size();
  int column=a[0].size();
  int c=row*column;
  if((c%stride)!=0)
      {cout<<"Pooling is not possible for this value of stride for this matrix"<<endl;                     //if the number of elemnts in the matrix is not an integral multiple of stride then pooling is not possible.
      exit(1);
      }
   vector<vector<float>> to_be_returned;                         //this is the resultant matrix that i have to return.
  for(int i=0;i<a.size();i=i+stride)
        { int j=0;
        vector<float>temp;                       
         float max=a.at(i).at(0);
                                             
                                                           //in the loop  i am taking groups of stride*stride elemnts from the given matrix then calculated the max among these and then add this max to resultant matrix
           int k=j;
        while(k<a.at(0).size())
            {     if(k>=j+stride)
                  {
                    j=j+stride;
                    max=a.at(i).at(k);
                        }
              
               for(int l=i;l<i+stride;l++) 
               {
                  if(a.at(l).at(k)>max)
                  max=a.at(l).at(k);
                    }              
            if(k==j+stride-1)
              temp.push_back(max);
  
            k++;

            
            }
  to_be_returned.push_back(temp);                                   
        }
    
return to_be_returned;                                               //finally returning the resultant matrix
}


vector<vector<float>>average_pooling(vector<vector<float>>a,int stride)
{ int row=a.size();
  int column=a[0].size();
  int c=row*column;
  if((c%stride)!=0)
      {cout<<"Pooling is not possible for this value of stride for this matrix"<<endl;                     //if the number of elemnts in the matrix is not an integral multiple of stride then pooling is not possible.
      exit(1);
      }
   vector<vector<float>> to_be_returned;                                        //this is the resultant matrix that i have to return.
  for(int i=0;i<a.size();i=i+stride)
        { int j=0;
        vector<float>temp;
         float sum_of_elements_in_the_stride=0;
          int k=j;
        while(k<a.at(0).size())
            {     if(k>=j+stride)
                  {                                                      //in the loop  i am taking groups of stride*stride elemnts from the given matrix then calculated the avg of all  these and then add this avg to resultant matrix
                    j=j+stride;
                    sum_of_elements_in_the_stride=0;
                  
                        }
              for(int l=i;l<i+stride;l++) 
               {
                  sum_of_elements_in_the_stride+=a.at(l).at(k);
                    }              
            if(k==j+stride-1)
              temp.push_back(sum_of_elements_in_the_stride/(stride*stride));
            
            k++;

            }
  to_be_returned.push_back(temp);                                                  //finally returning the resultant matrix
        }
    
return to_be_returned;
}



  

vector<float>Sigmoid_fn(vector<float> a)
{
for(int i=0;i<a.size();i++)                           //here we know that the softmax fn is defined as F(x)=1/(1+exp(-x))
                                                      //so here i replaced every elemnt of vector with above defination and finally returned the vector
  {
       float temp=a.at(i);
       a[i]=1/(1+exp(0-temp));
}

return a;

}
vector<float>Softmax_fn(vector<float>a)
{ float sum_of_exponential_of_all_elements_of_vector=0.0f;
    for(int i=0;i<a.size();i++)                                                   //as softmax fn is defined as F(x)=exp(x)/sum of all  element's exponential 
                                                                                   //so here also i had done the same thing i replaced every element of the vector acc to above defination and finally returned the vector
     sum_of_exponential_of_all_elements_of_vector+=exp(a.at(i));
     
            for(int i=0;i<a.size();i++)
             {
                 a[i]=(exp(a.at(i)))/sum_of_exponential_of_all_elements_of_vector; 
                    }
return a;

}

}; 
/*
./yourcode.out fullyconnected inputmatrix.txt weightmatrix.txt biasmatrix.txt outputmatrix.txt
./yourcode.out activation relu inputmatrix.txt outputmatrix.txt
./yourcode.out activation tanh inputmatrix.txt outputmatrix.txt
./yourcode.out pooling max inputmatrix.txt stride outputmatrix.txt
./yourcode.out pooling average inputmatrix.txt stride outputmatrix.txt
./yourcode.out probability softmax inputvector.txt outputvector.txt
./yourcode.out probability sigmoid inputvector.txt outputvector.txt
*/
int main(int argc, char** argv)
{ string matching1("./yourcode.outfullyconnected");
string matching2("./yourcode.outactivationrelu");
string matching3("./yourcode.outactivationtanh");
string matching4("./yourcode.outpoolingmax");
string matching5("./yourcode.outpoolingaverage");
string matching6("./yourcode.outprobabilitysoftmax");
string matching7("./yourcode.outprobabilitysigmoid");


  // ********************************************COMMAND LINE ERRORS HNDLING****************************************************************
  
  if(argc>6||argc<5)
  {
     cout<<"Invalid Command Line please try with only these command lines-"<<endl;
     cout<<endl;
     cout<<endl;
     cout<<"1-- "<<" ./yourcode.out fullyconnected inputmatrix.txt weightmatrix.txt biasmatrix.txt outputmatrix.txt"<<endl;
     cout<<"2-- "<<" ./yourcode.out activation relu inputmatrix.txt outputmatrix.txt"<<endl;
     cout<<"3-- "<<" ./yourcode.out activation tanh inputmatrix.txt outputmatrix.txt"<<endl;
     cout<<"4-- "<<" ./yourcode.out pooling max inputmatrix.txt stride outputmatrix.txt"<<endl;
     cout<<"5-- "<<" ./yourcode.out pooling average inputmatrix.txt stride outputmatrix.txt"<<endl;
     cout<<"6-- "<<" ./yourcode.out probability softmax inputvector.txt outputvector.txt"<<endl;
     cout<<"7-- "<<" ./yourcode.out probability sigmoid inputvector.txt outputvector.txt"<<endl;
exit(1);
  }
 
if(argc==5)
  {string to_be_matched;

for(int i=0;i<3;i++)
  {
    to_be_matched+=argv[i];
  }
  
 if(to_be_matched!=matching2&&to_be_matched!=matching3&&to_be_matched!=matching6&&to_be_matched!=matching7)
 {
  cout<<"Invalid Command Line please try with only these command lines-"<<endl;
      cout<<endl;
     cout<<endl;
      cout<<"1-- "<<"./yourcode.out fullyconnected inputmatrix.txt weightmatrix.txt biasmatrix.txt outputmatrix.txt"<<endl;
     cout<<"2-- "<<"./yourcode.out activation relu inputmatrix.txt outputmatrix.txt"<<endl;
     cout<<"3-- "<<"./yourcode.out activation tanh inputmatrix.txt outputmatrix.txt"<<endl;
     cout<<"4-- "<<"./yourcode.out pooling max inputmatrix.txt stride outputmatrix.txt"<<endl;
     cout<<"5-- "<<"./yourcode.out pooling average inputmatrix.txt stride outputmatrix.txt"<<endl;
     cout<<"6-- "<<"./yourcode.out probability softmax inputvector.txt outputvector.txt"<<endl;
     cout<<"7-- "<<"./yourcode.out probability sigmoid inputvector.txt outputvector.txt"<<endl;
exit(1);

 }

}

if(argc==6)
{
string w1;
for(int i=0;i<3;i++)
{w1.append(argv[i]);
}
if(w1!=matching4&&w1!=matching5)
  {  string h;
   for(int i=0;i<2;i++)
   h.append(argv[i]);

   if(h!=matching1)
   {
          cout<<"Invalid Command Line please try with only these command lines-"<<endl;
     cout<<"1-- "<<"./yourcode.out fullyconnected inputmatrix.txt weightmatrix.txt biasmatrix.txt outputmatrix.txt"<<endl;
     cout<<"2-- "<<"./yourcode.out activation relu inputmatrix.txt outputmatrix.txt"<<endl;
     cout<<"3-- "<<"./yourcode.out activation tanh inputmatrix.txt outputmatrix.txt"<<endl;
     cout<<"4-- "<<"./yourcode.out pooling max inputmatrix.txt stride outputmatrix.txt"<<endl;
     cout<<"5-- "<<"./yourcode.out pooling average inputmatrix.txt stride outputmatrix.txt"<<endl;
     cout<<"6-- "<<"./yourcode.out probability softmax inputvector.txt outputvector.txt"<<endl;
     cout<<"7--"<<"./yourcode.out probability sigmoid inputvector.txt outputvector.txt"<<endl;
exit(1);

   }


  }

    
  }

  // ********************************************COMMAND LINE ERRORS HNDLING****************************************************************
 
 
 
 
  Matrix_operations class_of_operations;
    string a(argv[1]);
    string b(argv[2]);
    
    
     //************************FOR SIGMOID PART******************************
                                                                                    //code to run sigmoid fn
    
    //***************************instream part*********
    
    if(a=="probability"&&b=="sigmoid")                                       
         { ifstream myfile;
         myfile.open(argv[3]);                                    //opening the targeted file that is read from commandline
         
          if(!myfile)
          {
            cout<<"File with name=" <<argv[3]<<" does not Exists"<<endl;                    //if file is not there then throwing error that file does not exists then exit the program
            exit(1);
          }
     else if(myfile.eof()==true)
      {
        cout<<"File with name ="<<argv[3]<<"is empty"<<endl;                              //if file is empty then throw file is empty error and then exit the program
         exit(1);
      }  
           
     vector<float> to_be_returned;                        //vector whose values will be written to targeted file
    int size=0;
    myfile>>size;
   float l;
   while(myfile>>l)
   {                                                                              //loop to write the data in the to_be returned vector
     to_be_returned.push_back(l);
   }
 
to_be_returned=class_of_operations.Sigmoid_fn(to_be_returned);                      //calling sigmoid function
myfile.close();

//**************************************ofstream part***************************

ofstream file;
file.open(argv[4]);
file<<size<<endl;                                                                    //writing the data to the targeted output file
for(int i=0;i<to_be_returned.size();i++)
{setprecision(5);
file<<to_be_returned[i]<<endl;

}

     } 

          //**************************FOR SOFTMAX PART************************************8

  
         //******************************instream part*****************

    else if(a=="probability"&&b=="softmax")
         { ifstream myfile;                                                 //opening the targeted file that is read from commandline
         myfile.open(argv[3]);
         
          if(!myfile)
          {
             cout<<"File with name = " <<argv[3]<<" does not Exists"<<endl;                           //if file is not there then throwing error that file does not exists then exit the program
            exit(1);
          }
     else if(myfile.eof()==true)
      {
        cout<<"File with name = "<<argv[3]<<"is empty"<<endl;                             //if file is empty then throw file is empty error and then exit the program
         exit(1);
      }  
           
     vector<float> to_be_returned;                           //vector whose values will be written to  targeted file
    int size=0;
    myfile>>size;
   float l;                
   while(myfile>>l)
   {
     to_be_returned.push_back(l);                       //loop to write the data in the to_be returned vector
   }
to_be_returned=class_of_operations.Softmax_fn(to_be_returned);                   //calling softmax function
myfile.close();

//*********************************ofstream part**************************************

ofstream file;
file.open(argv[4]);
file<<size<<endl;
for(int i=0;i<to_be_returned.size();i++)
{setprecision(5);
file<<to_be_returned[i]<<endl;                                   //writing the data to the targeted output file

}

     } 

//**********************************FOR RELU FUNCTION****************************************8
   
   
   //************************************instream part*********************
   
   
   
   if(a=="activation"&&b=="relu")
         { ifstream myfile;                           //opening the targeted file that is read from commandline
         myfile.open(argv[3]);
         
          if(!myfile)
          {
          cout<<"File with name = " <<argv[3]<<" does not Exists"<<endl;                     //if file is not there then throwing error that file does not exists then exit the program
            exit(1);
          }
     else if(myfile.eof()==true)
      {
         cout<<"File with name = "<<argv[3]<<"is empty"<<endl;
         exit(1);                                                       //if file is empty then throw file is empty error and then exit the program
      }  
        int column;
        myfile>>column;
        
        int row;
        myfile>>row;

vector<vector<float>>to_be_returned;                         //vector whose values will be written to  targeted file

int j=0;
int i=0;
vector<float>temp; 
 float  l=0;
while(myfile>>l)
{ 
   if(i==row-1)
    { 
      temp.push_back(l);
      to_be_returned.push_back(temp);                                //loop to write the data in to_be_returned vector
      temp.clear();
        i=0;
      continue;
   }

temp.push_back(l);
i++;

}



to_be_returned=class_of_operations.relu_fn(to_be_returned);                    // calling relu fn


//************************************ofstream part*******************************

ofstream file;
file.open(argv[4]);

file<<column<<endl;

file<<row<<endl;


int count=0;

for(int i=0;i<to_be_returned.size();i++)
{     setprecision(5);                                                   //  //writing the data to the targeted output file
        for(int j=0;j<to_be_returned[i].size();j++)
           file<<to_be_returned[i][j]<<endl;   
  

}

}


//*****************************************FOR TANH FUNCTION**************************************


        //*********************************instream part********************

   if(a=="activation"&&b=="tanh")
         { ifstream myfile;                                                   //opening the targeted file that is read from commandline
         myfile.open(argv[3]);
         
          if(!myfile)
          {
             cout<<"File with name = " <<argv[3]<<" does not Exists"<<endl;                                 //if file is not there then throwing error that file does not exists then exit the program
            exit(1);
          }
     else if(myfile.eof()==true)
      {
        cout<<"File with name = "<<argv[3]<<"is empty"<<endl;                                   //if file is empty then throw file is empty error and then exit the program          
         exit(1);
      }  
        int column;
        myfile>>column;
        
        int row;
        myfile>>row;

vector<vector<float>>to_be_returned;                              //vector whose values will be written to  targeted file

int j=0;
int i=0;
vector<float>temp; 
 float l=0;
while(myfile>>l)
{ 
   if(i==row-1)
    { 
      temp.push_back(l);
      to_be_returned.push_back(temp);                                //loop to write the data in to_be_returned vector
      temp.clear();
        i=0;
      continue;
   }

temp.push_back(l);
i++;

}

 
to_be_returned=class_of_operations.tanh_fn(to_be_returned);


//********************************ofstream part**************************************

ofstream file;
file.open(argv[4]);

file<<column<<endl;

file<<row<<endl;


int count=0;

for(int i=0;i<to_be_returned.size();i++)
{     setprecision(5);
        for(int j=0;j<to_be_returned[i].size();j++)                               //  //writing the data to the targeted output file
           file<<to_be_returned[i][j]<<endl;   
  

}

}


          //***********************************FOR POOLING MAX FUNCTION****************************************




        //**************************************instream part********************

   if(a=="pooling"&&b=="max")
         { ifstream myfile;
         myfile.open(argv[3]);                                      //opening the targeted file that is read from commandline
         
          if(!myfile)
          {
            cout<<"File with name =" <<argv[3]<<" does not Exists"<<endl;                             //if file is not there then throwing error that file does not exists then exit the program
            exit(1);
          }
     else if(myfile.eof()==true)
      {
         cout<<"File with name = "<<argv[3]<<"is empty"<<endl;                                   //if file is empty then throw file is empty error and then exit the program
         exit(1);
      }  
        int column;                                         //here column is the column of the inputed matrix
        myfile>>column;
        
        int row;
        myfile>>row;                                        //here row is the number of rows in the inputed matrix

vector<vector<float>>to_be_returned;                     //vector whose values will be written to  targeted file

int j=0;
int i=0;
vector<float> array[row];                              //array with row number of  vectors
 float l=0;
while(myfile>>l)
{ 
   if(i==row-1)
    { 
      array[i].push_back(l);                     //loop to fill the data in the vector array defined above
        i=0;
      continue;
   }

array[i].push_back(l);
i++;

}



for(int i=0;i<row;i++)
{

   to_be_returned.push_back(array[i]);                    // //loop to write the data in to_be_returned vector from array
}


int stride=atoi(argv[4]);

if(stride<0)
{
  cout<<"Stride is Invalid"<<endl;
  exit(1);
}




to_be_returned=class_of_operations.max_pooling(to_be_returned,stride);                 //calling max_pooling function




//*********************************ofstream part**********************************

ofstream file;
file.open(argv[5]);

file<<to_be_returned.at(0).size()<<endl;

file<<to_be_returned.size()<<endl;



int count=0;

     setprecision(5);
        for(int j=0;j<to_be_returned[0].size();j++)
         {     for(int k=0;k<to_be_returned.size();k++)
              {
                     file<<to_be_returned[k][j]<<endl;                              //writing to targeted file                         
              }   
  
         }
}





    //***********************************FOR POOLING AVERAGE FUNCTION****************************************




        //***********************************instream part********************

   if(a=="pooling"&&b=="average")
         { ifstream myfile;
         myfile.open(argv[3]);                                         //opening the targeted file that is read from commandline
         
          if(!myfile)
          {
            cout<<"File with name =" <<argv[3]<<" does not Exists"<<endl;                             //if file is not there then throwing error that file does not exists then exit the program
            exit(1);
          }
     else if(myfile.eof()==true)
      {
        cout<<"File with name = "<<argv[3]<<"is empty"<<endl;                                 //if file is empty then throw file is empty error and then exit the program
         exit(1);
      }  
        int column;
        myfile>>column;                                        //here column is the column of the inputed matrix
        
        int row;
        myfile>>row;                                            //here row is the number of rows in the inputed matrix

vector<vector<float>>to_be_returned;                       //vector whose values will be written to  targeted file

int j=0;
int i=0;
vector<float> array[row];                                 //array with row number of  vectors
 float  l=0;
while(myfile>>l)
{ 
   if(i==row-1)
    { 
      array[i].push_back(l);                               //loop to fill the data in the vector array defined above
        i=0;
      continue;
   }

array[i].push_back(l);
i++;

}



for(int i=0;i<row;i++)
{
 
   to_be_returned.push_back(array[i]);                                // //loop to write the data in to_be_returned vector from array
}


int stride=atoi(argv[4]);
if(stride<0)
{
  cout<<"Stride is Invalid"<<endl;
  exit(1);
}




to_be_returned=class_of_operations.average_pooling(to_be_returned,stride);       //calling average_pooling function



//*********************************ofstream part*********************************************

ofstream file;
file.open(argv[5]);

file<<to_be_returned.at(0).size()<<endl;

file<<to_be_returned.size()<<endl;



int count=0;

     setprecision(5);
        for(int j=0;j<to_be_returned[0].size();j++)
         {     for(int k=0;k<to_be_returned.size();k++)
              {
                     file<<to_be_returned[k][j]<<endl;                               //writing to targeted file  
              }   
  
         }
}




 //***********************************FOR FULLY_CONNECTED LAYER FUNCTION****************************************




              //***********************************instream part********************

   if(a=="fullyconnected")
         { vector<vector<float>>a;
          vector<vector<float>>weight_matrix;
          vector<vector<float>>bias_matrix;
           ifstream myfile;
           ifstream myfile1;
           ifstream myfile2;
         myfile.open(argv[2]);                                             //opening the file of inputmatrix
         
          if(!myfile)
          {
             cout<<"File with name = " <<argv[2]<<" does not Exists"<<endl;  
            exit(1);                                                    //if file not present then throw file not found error and exit the program
          }
     else if(myfile.eof()==true)
      {
         cout<<"File with name = "<<argv[2]<<"is empty"<<endl;                                       //if file is empty then throw empty file  error
         exit(1);
      }  
        int column1;                                   //column of inputmatrix
        myfile>>column1;
        
        int row1;
        myfile>>row1;                                     //row of input matrix

vector<vector<float>>to_be_returned;                              //vector whose values will be written to the targeted output file

int j=0;
int i=0;
vector<float> array[row1];                         // array of vectors with number of  elements equal to row1
 float l=0;
while(myfile>>l)
{ 
   if(i==row1-1)
    {                                            //writing the data into the array
      array[i].push_back(l);
        i=0;
      continue;
   }
array[i].push_back(l);
i++;

}



for(int i=0;i<row1;i++)
{
   a.push_back(array[i]);                                   //transferring the data from the array to  inputmatrix_vector i.e a
}
myfile.close();


myfile1.open(argv[3]);

 if(!myfile1)                                                   ////opening the file of weightmatrix

  {
            cout<<"File with name = " <<argv[3]<<" does not Exists"<<endl;                     //if file of weightmatrix is not presesnt then throw file not found error and exit the program
                        exit(1);
          }
     else if(myfile1.eof()==true)
      {
         cout<<"File with name = "<<argv[3]<<"is empty"<<endl;                        //if file of weightmatrix is empty then throw empty error and exit the program
         exit(1);
      }  
        int column2;
        myfile1>>column2;                          //column of biasmatrix
        
        int row2;
        myfile1>>row2;                           //row of biasmatrix 

      i=0;
      j=0;


vector<float> array2[row2];                         //array with row2 elements of vector 
  l=0;
while(myfile1>>l)
{ 
   if(i==row2-1)
    { 
                                                     //loop to fill the array2 from myfile1
      array2[i].push_back(l);
        i=0;
      continue;
   }

array2[i].push_back(l);
i++;

}


for(int i=0;i<row2;i++)
{
 
   weight_matrix.push_back(array2[i]);                         //pushing elements from array3 to weightmatrix vector
}


myfile1.close();

myfile2.open(argv[4]);           //opening the file of biasmatrix


 if(!myfile2)
          {
            cout<<"File with name =" <<argv[4]<<" does not Exists"<<endl;                //if file of biasmatrix is not presesnt then throw file not found error and exit the program
            exit(1);
          }
     else if(myfile2.eof()==true)
      {
         cout<<"File with name = "<<argv[4]<<"is empty"<<endl;                           //if file of biasmatrix is empty then throw empty error and exit the program
         exit(1);
      }  
        int column3;                                               //column of biasmatrix
        myfile2>>column3;
        
        int row3;                                   //row of biasmatrix 
        myfile2>>row3;

      i=0;
      j=0;


vector<float> array3[row3];                        //array with row3 elements of vector 
  l=0;
while(myfile2>>l)
{ 
   if(i==row3-1)
    { 
                                             //loop to fill the array3 from myfile2
      array3[i].push_back(l);
        i=0;
      continue;
   }

array3[i].push_back(l);
i++;

}


for(int i=0;i<row3;i++)
{
                                                         //pushing elements from array3 to bias vector
   bias_matrix.push_back(array3[i]);
}


to_be_returned=class_of_operations.fully_connected_layer(a,weight_matrix,bias_matrix);            //calling fullyconnectedlayer fn


//*********************************ofstream part*********************************************

ofstream file;
file.open(argv[5]);

file<<to_be_returned.at(0).size()<<endl;                   //writing to the file

file<<to_be_returned.size()<<endl;                   //writing to the file



     setprecision(5);
        for(int j=0;j<to_be_returned[0].size();j++)
         {     for(int k=0;k<to_be_returned.size();k++)
              {
                     file<<to_be_returned[k][j]<<endl;                       //writing to the file
              }   
  
         }
}


return 0;
}





