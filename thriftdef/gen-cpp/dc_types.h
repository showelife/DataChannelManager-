/**
 * Autogenerated by Thrift Compiler (0.12.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef dc_TYPES_H
#define dc_TYPES_H

#include <iosfwd>

#include <thrift/Thrift.h>
#include <thrift/TApplicationException.h>
#include <thrift/TBase.h>
#include <thrift/protocol/TProtocol.h>
#include <thrift/transport/TTransport.h>

#include <thrift/stdcxx.h>




typedef int32_t int;

typedef int16_t short;

typedef int64_t long;

class user;

class FileData;

typedef struct _user__isset {
  _user__isset() : name(false) {}
  bool name :1;
} _user__isset;

class user : public virtual ::apache::thrift::TBase {
 public:

  user(const user&);
  user& operator=(const user&);
  user() : name() {
  }

  virtual ~user() throw();
  std::string name;

  _user__isset __isset;

  void __set_name(const std::string& val);

  bool operator == (const user & rhs) const
  {
    if (!(name == rhs.name))
      return false;
    return true;
  }
  bool operator != (const user &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const user & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(user &a, user &b);

std::ostream& operator<<(std::ostream& out, const user& obj);


class FileData : public virtual ::apache::thrift::TBase {
 public:

  FileData(const FileData&);
  FileData& operator=(const FileData&);
  FileData() : name(), buff() {
  }

  virtual ~FileData() throw();
  std::string name;
  std::string buff;

  void __set_name(const std::string& val);

  void __set_buff(const std::string& val);

  bool operator == (const FileData & rhs) const
  {
    if (!(name == rhs.name))
      return false;
    if (!(buff == rhs.buff))
      return false;
    return true;
  }
  bool operator != (const FileData &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const FileData & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

  virtual void printTo(std::ostream& out) const;
};

void swap(FileData &a, FileData &b);

std::ostream& operator<<(std::ostream& out, const FileData& obj);



#endif