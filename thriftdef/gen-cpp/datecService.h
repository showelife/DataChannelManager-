/**
 * Autogenerated by Thrift Compiler (0.12.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef datecService_H
#define datecService_H

#include <thrift/transport/TBufferTransports.h>
#include <thrift/stdcxx.h>
namespace apache { namespace thrift { namespace async {
class TAsyncChannel;
}}}
#include <thrift/TDispatchProcessor.h>
#include <thrift/async/TAsyncDispatchProcessor.h>
#include <thrift/async/TConcurrentClientSyncInfo.h>
#include "dc_types.h"



#ifdef _MSC_VER
  #pragma warning( push )
  #pragma warning (disable : 4250 ) //inheriting methods via dominance 
#endif

class datecServiceIf {
 public:
  virtual ~datecServiceIf() {}
  virtual void stringInfo(std::string& _return, const std::string& s) = 0;
  virtual void heart(const std::string& s) = 0;
};

class datecServiceIfFactory {
 public:
  typedef datecServiceIf Handler;

  virtual ~datecServiceIfFactory() {}

  virtual datecServiceIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(datecServiceIf* /* handler */) = 0;
};

class datecServiceIfSingletonFactory : virtual public datecServiceIfFactory {
 public:
  datecServiceIfSingletonFactory(const ::apache::thrift::stdcxx::shared_ptr<datecServiceIf>& iface) : iface_(iface) {}
  virtual ~datecServiceIfSingletonFactory() {}

  virtual datecServiceIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(datecServiceIf* /* handler */) {}

 protected:
  ::apache::thrift::stdcxx::shared_ptr<datecServiceIf> iface_;
};

class datecServiceNull : virtual public datecServiceIf {
 public:
  virtual ~datecServiceNull() {}
  void stringInfo(std::string& /* _return */, const std::string& /* s */) {
    return;
  }
  void heart(const std::string& /* s */) {
    return;
  }
};

typedef struct _datecService_stringInfo_args__isset {
  _datecService_stringInfo_args__isset() : s(false) {}
  bool s :1;
} _datecService_stringInfo_args__isset;

class datecService_stringInfo_args {
 public:

  datecService_stringInfo_args(const datecService_stringInfo_args&);
  datecService_stringInfo_args& operator=(const datecService_stringInfo_args&);
  datecService_stringInfo_args() : s() {
  }

  virtual ~datecService_stringInfo_args() throw();
  std::string s;

  _datecService_stringInfo_args__isset __isset;

  void __set_s(const std::string& val);

  bool operator == (const datecService_stringInfo_args & rhs) const
  {
    if (!(s == rhs.s))
      return false;
    return true;
  }
  bool operator != (const datecService_stringInfo_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const datecService_stringInfo_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class datecService_stringInfo_pargs {
 public:


  virtual ~datecService_stringInfo_pargs() throw();
  const std::string* s;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _datecService_stringInfo_result__isset {
  _datecService_stringInfo_result__isset() : success(false) {}
  bool success :1;
} _datecService_stringInfo_result__isset;

class datecService_stringInfo_result {
 public:

  datecService_stringInfo_result(const datecService_stringInfo_result&);
  datecService_stringInfo_result& operator=(const datecService_stringInfo_result&);
  datecService_stringInfo_result() : success() {
  }

  virtual ~datecService_stringInfo_result() throw();
  std::string success;

  _datecService_stringInfo_result__isset __isset;

  void __set_success(const std::string& val);

  bool operator == (const datecService_stringInfo_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const datecService_stringInfo_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const datecService_stringInfo_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _datecService_stringInfo_presult__isset {
  _datecService_stringInfo_presult__isset() : success(false) {}
  bool success :1;
} _datecService_stringInfo_presult__isset;

class datecService_stringInfo_presult {
 public:


  virtual ~datecService_stringInfo_presult() throw();
  std::string* success;

  _datecService_stringInfo_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _datecService_heart_args__isset {
  _datecService_heart_args__isset() : s(false) {}
  bool s :1;
} _datecService_heart_args__isset;

class datecService_heart_args {
 public:

  datecService_heart_args(const datecService_heart_args&);
  datecService_heart_args& operator=(const datecService_heart_args&);
  datecService_heart_args() : s() {
  }

  virtual ~datecService_heart_args() throw();
  std::string s;

  _datecService_heart_args__isset __isset;

  void __set_s(const std::string& val);

  bool operator == (const datecService_heart_args & rhs) const
  {
    if (!(s == rhs.s))
      return false;
    return true;
  }
  bool operator != (const datecService_heart_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const datecService_heart_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class datecService_heart_pargs {
 public:


  virtual ~datecService_heart_pargs() throw();
  const std::string* s;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

class datecServiceClient : virtual public datecServiceIf {
 public:
  datecServiceClient(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  datecServiceClient(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void stringInfo(std::string& _return, const std::string& s);
  void send_stringInfo(const std::string& s);
  void recv_stringInfo(std::string& _return);
  void heart(const std::string& s);
  void send_heart(const std::string& s);
 protected:
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class datecServiceProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  ::apache::thrift::stdcxx::shared_ptr<datecServiceIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (datecServiceProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_stringInfo(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_heart(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  datecServiceProcessor(::apache::thrift::stdcxx::shared_ptr<datecServiceIf> iface) :
    iface_(iface) {
    processMap_["stringInfo"] = &datecServiceProcessor::process_stringInfo;
    processMap_["heart"] = &datecServiceProcessor::process_heart;
  }

  virtual ~datecServiceProcessor() {}
};

class datecServiceProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  datecServiceProcessorFactory(const ::apache::thrift::stdcxx::shared_ptr< datecServiceIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::apache::thrift::stdcxx::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::apache::thrift::stdcxx::shared_ptr< datecServiceIfFactory > handlerFactory_;
};

class datecServiceMultiface : virtual public datecServiceIf {
 public:
  datecServiceMultiface(std::vector<apache::thrift::stdcxx::shared_ptr<datecServiceIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~datecServiceMultiface() {}
 protected:
  std::vector<apache::thrift::stdcxx::shared_ptr<datecServiceIf> > ifaces_;
  datecServiceMultiface() {}
  void add(::apache::thrift::stdcxx::shared_ptr<datecServiceIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  void stringInfo(std::string& _return, const std::string& s) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->stringInfo(_return, s);
    }
    ifaces_[i]->stringInfo(_return, s);
    return;
  }

  void heart(const std::string& s) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->heart(s);
    }
    ifaces_[i]->heart(s);
  }

};

// The 'concurrent' client is a thread safe client that correctly handles
// out of order responses.  It is slower than the regular client, so should
// only be used when you need to share a connection among multiple threads
class datecServiceConcurrentClient : virtual public datecServiceIf {
 public:
  datecServiceConcurrentClient(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
    setProtocol(prot);
  }
  datecServiceConcurrentClient(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    setProtocol(iprot,oprot);
  }
 private:
  void setProtocol(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) {
  setProtocol(prot,prot);
  }
  void setProtocol(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) {
    piprot_=iprot;
    poprot_=oprot;
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
 public:
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  void stringInfo(std::string& _return, const std::string& s);
  int32_t send_stringInfo(const std::string& s);
  void recv_stringInfo(std::string& _return, const int32_t seqid);
  void heart(const std::string& s);
  void send_heart(const std::string& s);
 protected:
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
  ::apache::thrift::async::TConcurrentClientSyncInfo sync_;
};

class datecServiceCobClient;

class datecServiceCobClIf {
 public:
  virtual ~datecServiceCobClIf() {}
  virtual void stringInfo(::apache::thrift::stdcxx::function<void(datecServiceCobClient* client)> cob, const std::string& s) = 0;
  virtual void heart(::apache::thrift::stdcxx::function<void(datecServiceCobClient* client)> cob, const std::string& s) = 0;
};

class datecServiceCobSvIf {
 public:
  virtual ~datecServiceCobSvIf() {}
  virtual void stringInfo(::apache::thrift::stdcxx::function<void(std::string const& _return)> cob, const std::string& s) = 0;
  virtual void heart(::apache::thrift::stdcxx::function<void()> cob, const std::string& s) = 0;
};

class datecServiceCobSvIfFactory {
 public:
  typedef datecServiceCobSvIf Handler;

  virtual ~datecServiceCobSvIfFactory() {}

  virtual datecServiceCobSvIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(datecServiceCobSvIf* /* handler */) = 0;
};

class datecServiceCobSvIfSingletonFactory : virtual public datecServiceCobSvIfFactory {
 public:
  datecServiceCobSvIfSingletonFactory(const ::apache::thrift::stdcxx::shared_ptr<datecServiceCobSvIf>& iface) : iface_(iface) {}
  virtual ~datecServiceCobSvIfSingletonFactory() {}

  virtual datecServiceCobSvIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(datecServiceCobSvIf* /* handler */) {}

 protected:
  ::apache::thrift::stdcxx::shared_ptr<datecServiceCobSvIf> iface_;
};

class datecServiceCobSvNull : virtual public datecServiceCobSvIf {
 public:
  virtual ~datecServiceCobSvNull() {}
  void stringInfo(::apache::thrift::stdcxx::function<void(std::string const& _return)> cob, const std::string& /* s */) {
    std::string _return;
    return cob(_return);
  }
  void heart(::apache::thrift::stdcxx::function<void()> cob, const std::string& /* s */) {
    return cob();
  }
};

class datecServiceCobClient : virtual public datecServiceCobClIf {
 public:
  datecServiceCobClient(apache::thrift::stdcxx::shared_ptr< ::apache::thrift::async::TAsyncChannel> channel, ::apache::thrift::protocol::TProtocolFactory* protocolFactory) :
    channel_(channel),
    itrans_(new ::apache::thrift::transport::TMemoryBuffer()),
    otrans_(new ::apache::thrift::transport::TMemoryBuffer()),
    piprot_(protocolFactory->getProtocol(itrans_)),
    poprot_(protocolFactory->getProtocol(otrans_)) {
    iprot_ = piprot_.get();
    oprot_ = poprot_.get();
  }
  ::apache::thrift::stdcxx::shared_ptr< ::apache::thrift::async::TAsyncChannel> getChannel() {
    return channel_;
  }
  virtual void completed__(bool /* success */) {}
  void stringInfo(::apache::thrift::stdcxx::function<void(datecServiceCobClient* client)> cob, const std::string& s);
  void send_stringInfo(const std::string& s);
  void recv_stringInfo(std::string& _return);
  void heart(::apache::thrift::stdcxx::function<void(datecServiceCobClient* client)> cob, const std::string& s);
  void send_heart(const std::string& s);
 protected:
  ::apache::thrift::stdcxx::shared_ptr< ::apache::thrift::async::TAsyncChannel> channel_;
  ::apache::thrift::stdcxx::shared_ptr< ::apache::thrift::transport::TMemoryBuffer> itrans_;
  ::apache::thrift::stdcxx::shared_ptr< ::apache::thrift::transport::TMemoryBuffer> otrans_;
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  apache::thrift::stdcxx::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class datecServiceAsyncProcessor : public ::apache::thrift::async::TAsyncDispatchProcessor {
 protected:
  ::apache::thrift::stdcxx::shared_ptr<datecServiceCobSvIf> iface_;
  virtual void dispatchCall(::apache::thrift::stdcxx::function<void(bool ok)> cob, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid);
 private:
  typedef  void (datecServiceAsyncProcessor::*ProcessFunction)(::apache::thrift::stdcxx::function<void(bool ok)>, int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_stringInfo(::apache::thrift::stdcxx::function<void(bool ok)> cob, int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot);
  void return_stringInfo(::apache::thrift::stdcxx::function<void(bool ok)> cob, int32_t seqid, ::apache::thrift::protocol::TProtocol* oprot, void* ctx, const std::string& _return);
  void throw_stringInfo(::apache::thrift::stdcxx::function<void(bool ok)> cob, int32_t seqid, ::apache::thrift::protocol::TProtocol* oprot, void* ctx, ::apache::thrift::TDelayedException* _throw);
  void process_heart(::apache::thrift::stdcxx::function<void(bool ok)> cob, int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot);
  void return_heart(::apache::thrift::stdcxx::function<void(bool ok)> cob, int32_t seqid, ::apache::thrift::protocol::TProtocol* oprot, void* ctx);
  void throw_heart(::apache::thrift::stdcxx::function<void(bool ok)> cob, int32_t seqid, ::apache::thrift::protocol::TProtocol* oprot, void* ctx, ::apache::thrift::TDelayedException* _throw);
 public:
  datecServiceAsyncProcessor(::apache::thrift::stdcxx::shared_ptr<datecServiceCobSvIf> iface) :
    iface_(iface) {
    processMap_["stringInfo"] = &datecServiceAsyncProcessor::process_stringInfo;
    processMap_["heart"] = &datecServiceAsyncProcessor::process_heart;
  }

  virtual ~datecServiceAsyncProcessor() {}
};

class datecServiceAsyncProcessorFactory : public ::apache::thrift::async::TAsyncProcessorFactory {
 public:
  datecServiceAsyncProcessorFactory(const ::apache::thrift::stdcxx::shared_ptr< datecServiceCobSvIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::apache::thrift::stdcxx::shared_ptr< ::apache::thrift::async::TAsyncProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::apache::thrift::stdcxx::shared_ptr< datecServiceCobSvIfFactory > handlerFactory_;
};

#ifdef _MSC_VER
  #pragma warning( pop )
#endif



#endif
