#include "Thing.h"

#include <string>

using namespace potd;


  Thing::Thing(int size) {
    properties_= new std::string[size];
    values_=new std::string[size];
    props_ct_=0;
    props_max_=size;
  }

  void Thing::_destroy()
  {
  	delete [] properties_;
    delete [] values_;
  	properties_ = NULL;
    values_ = NULL;
  }

  void Thing::_copy(const Thing & other)
  {
    props_ct_= other.props_ct_;
    props_max_= other.props_max_;
    properties_= new std::string[props_max_];
    values_=new std::string[props_max_];
    for (int i=0; i<props_ct_;i++){
        properties_[i]= other.properties_[i];
        values_[i]= other.values_[i];
      }
  }



  Thing::~Thing(){
    //delete [] properties_;
    //delete [] values_;
    _destroy();
  }

  //Thing::Thing(const Thing & other) {
  //  props_ct_= other.props_ct_;
  //  props_max_= other.props_max_;
  //  properties_= new std::string[props_ct_-1];
  //  values_=new std::string[props_ct_-1];
  //  for (int i=0; i<props_ct_;i++){
  //    properties_[i]= other.properties_[i];
  //    values_[i]= other.values_[i];
  //  }
  //}

  //Thing& Thing::operator=(const Thing & other){
    //    if (this == &other) {
  	//      return *this;
    //    } else {
    //    _destroy();
    //    _copy(other);
    //    return *this;
    //  }
    //}

    Thing::Thing(const Thing & other)
{
	_copy(other);
}


Thing& Thing::operator=(const Thing & other)
{
	if (this != &other)
	{
		_destroy();
		_copy(other);
	}
	return *this;
}

  int Thing::set_property(std::string name, std::string value) {
    if (props_ct_<props_max_){
      for(int i=0;i<props_ct_;i++){
        if (this->properties_[i]==name){
          this->values_[i]=value;
          return i;
        }
      }
        // else{
        properties_[props_ct_]=name;
        values_[props_ct_]=value;
        props_ct_=props_ct_+1;
        return props_ct_-1;
      // }
    }
    else{
      for(int i=0;i<props_ct_;i++){
        if (this->properties_[i]==name){
          this->values_[i]=value;
          return i;
        }
      }
      return -1;
    }
  }

  std::string Thing::get_property(std::string name){

      for(int i=0;i<props_ct_;i++){
        if (this->properties_[i]==name){
          return this->values_[i];
          }
      }
      return "";
    }
