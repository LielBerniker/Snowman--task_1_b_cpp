#include "snowman.hpp"
#include <array>
#include <stdexcept>
#include <string>
using namespace std;

const string H1 = "_===_\n";
const string H21 = " ___\n";
const string H22 = ".....\n";
const string H31 = "  _\n";
const string H32 = " /_\\\n";
const string H41 = " ___\n";
const string H42 = "(_*_)\n";
const string N1 = ",";
const string N2 = ".";
const string N3 = "_";
const string N4 = " ";
const string E1 = ".";
const string E2 = "o";
const string E3 = "O";
const string E4 = "-";
const string AL1 = "<";
const string AL2 = "\\";
const string AL3 = "/";
const string AR1 = ">";
const string AR2 = "/";
const string AR3 = "\\";
const string T1 = "( : )";
const string T2 = "(] [)";
const string T3 = "(> <)";
const string T4 = "(   )";
const string B1 = "( : )\n";
const string B2 = "(\" \")\n";
const string B3 = "(___)\n";
const string B4 = "(   )\n";
const int LOWER = 11111111;
const int HIGHER = 44444444;
const int TEN = 10;
const int SEVEN = 7;
const int SIX = 6;
const int FIVE = 5;
const int ZERO = 0;
const int TWO =2;
const int ONE =1;
const int THREE = 3;




 bool ariel::check_currect(int seq)
    {
        // this function check if the number is currect for creating a snow man
        // threnumber need to contain 8 digits that the digit should be : 1 <= x <= 4 such as x is one of the digits
        int temp = 0;
        int dig = 0;
        // check if the number contain 8 digits
        if(seq < LOWER || seq > HIGHER)
           {return false;}
        temp = seq;
        // check if one of the digits is not between 1 to 4 include
        for (int i = 0; i <DIGIT_COUNT; i++)
        {
            dig = temp%TEN;
            if(dig ==0 || dig >4)
            {return false;}
            temp = temp /TEN;
        }
        return true;  
    }
  std::string ariel::get_base(int base,std::string const &left)
  {
      // return the wright string for the number of digit that represent the base
      std::string base_new;
      switch (base)
      {
      case 1:
          base_new.append( left + B1);
          break;
      case 2:
          base_new.append( left + B2);
          break;
      case 3:
          base_new.append( left + B3);
          break;
      case 4:
          base_new.append( left + B4);
          break;
      
      default:
          break;
      }
      return base_new;
  }
    string ariel::get_torso(int tor,string const &left,string const &right)
  {

      // return the wright string for the number of digit that represent the torso
      std::string tor_new;
      switch (tor)
      {
      case 1:
          tor_new.append(left + T1 + right);
          break;
      case 2:
          tor_new.append(left + T2 + right);
          break;
      case 3:
          tor_new.append(left + T3 + right);
          break;
      case 4:
          tor_new.append(left + T4 + right);
          break;
      
      default:
          break;
      }
      return tor_new;
  }
      string ariel::get_hat(int hat,string const &left)
  {
      // return the wright string for the number of digit that represent the hat
      std::string hat_new;
      switch (hat)
      {
      case 1:
          hat_new.append(left + H1);
          break;
      case 2:
          hat_new.append(left + H21 + left + H22);
          break;
      case 3:
          hat_new.append(left + H31 + left + H32);
          break;
      case 4:
          hat_new.append(left + H41 + left + H42);
          break;
      
      default:
          break;
      }
      return hat_new;
  }
 std::string ariel::get_eye(int eye)
  {
      // return the wright string for the number of digit that represent the eye
      std::string eye_new;
      switch (eye)
      {
      case 1:
          eye_new.append(E1);
          break;
      case 2:
          eye_new.append(E2);
          break;
      case 3:
          eye_new.append(E3);
          break;
      case 4:
          eye_new.append(E4);
          break;
      
      default:
          break;
      }
      return eye_new;
  }
string ariel::get_nose(int nose)
  {
      // return the wright string for the number of digit that represent the nose
      string nose_new;
      switch (nose)
      {
      case 1:
          nose_new.append(N1);
          break;
      case 2:
          nose_new.append(N2);
          break;
      case 3:
          nose_new.append(N3);
          break;
      case 4:
          nose_new.append(N4);
          break;
      
      default:
          break;
      }
      return nose_new;
  }
  string ariel::get_parts(const std::array<int, DIGIT_COUNT> &arr)
  {
      // fil; the array of string with the 4 parts of the snow man (hat,face,torso,base)
      // according to the numbers represent the part in the int arr
      string all_man;
      string left_hat =" ";
      string left_face;
      string right_face;
      string left_tor;
      string right_tor;
      string left_base=" ";
    // check if need to add hands or space ib differnt part in the snowman
   if(arr.at(PART_COUNT)==2)
   {
       left_face = AL2;
       left_tor = " ";
   }
   else if(arr.at(PART_COUNT) == 1)
   {
       left_face = " ";
       left_tor = AL1;
   }
   else if(arr.at(PART_COUNT) == 3)
   {
      left_face = " ";
       left_tor = AL3;
   }
   else
   {
       left_hat ="";
       left_base ="";
   }
   if(arr.at(FIVE) == 1)
     {right_tor = AR1;}
   else if(arr.at(FIVE) == 2)
     {right_face = AR2;}
   else if (arr.at(FIVE)== 3)
    {right_tor = AR3;}

    // the hat part of the snowman
    all_man.append(get_hat(arr.at(ZERO),left_hat));
        // add to the face part of the snowman
    all_man.append(left_face + "(" + get_eye(arr.at(TWO)) + get_nose(arr.at(ONE)) + get_eye(arr.at(THREE)) +")" + right_face + "\n");
        // the torso part of the snowman
    all_man.append(get_torso(arr.at(SIX),left_tor,right_tor) + "\n");
    // the base part of the snowman
    all_man.append(get_base(arr.at(SEVEN),left_base));


  return all_man;

  } 
 

   string ariel::snowman(int seq)
{
   string full_man;
   int temp = seq;
   int dig = 0;
   std::array<int, DIGIT_COUNT> arr={};
  
   if(!ariel::check_currect(seq))
        {throw "not a good number to transform to a snowman";
        return "";}
    for (int i = DIGIT_COUNT-1; i >=0 ; i--)
    {
         dig = temp%TEN;
         arr.at(i) = dig;
         temp = temp/TEN;
    }
    full_man  = get_parts(arr);

   return full_man;

}
