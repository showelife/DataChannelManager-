/**
 * Autogenerated by Thrift Compiler (0.12.0)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#include "FileInfoExtractService.h"
#include "thrift/async/TAsyncChannel.h"




FileInfoExtractService_uploadFile_args::~FileInfoExtractService_uploadFile_args() throw() {
}


uint32_t FileInfoExtractService_uploadFile_args::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 1:
        if (ftype == ::apache::thrift::protocol::T_STRUCT) {
          xfer += this->filedata.read(iprot);
          this->__isset.filedata = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t FileInfoExtractService_uploadFile_args::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("FileInfoExtractService_uploadFile_args");

  xfer += oprot->writeFieldBegin("filedata", ::apache::thrift::protocol::T_STRUCT, 1);
  xfer += this->filedata.write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


FileInfoExtractService_uploadFile_pargs::~FileInfoExtractService_uploadFile_pargs() throw() {
}


uint32_t FileInfoExtractService_uploadFile_pargs::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("FileInfoExtractService_uploadFile_pargs");

  xfer += oprot->writeFieldBegin("filedata", ::apache::thrift::protocol::T_STRUCT, 1);
  xfer += (*(this->filedata)).write(oprot);
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


FileInfoExtractService_uploadFile_result::~FileInfoExtractService_uploadFile_result() throw() {
}


uint32_t FileInfoExtractService_uploadFile_result::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 0:
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool(this->success);
          this->__isset.success = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t FileInfoExtractService_uploadFile_result::write(::apache::thrift::protocol::TProtocol* oprot) const {

  uint32_t xfer = 0;

  xfer += oprot->writeStructBegin("FileInfoExtractService_uploadFile_result");

  if (this->__isset.success) {
    xfer += oprot->writeFieldBegin("success", ::apache::thrift::protocol::T_BOOL, 0);
    xfer += oprot->writeBool(this->success);
    xfer += oprot->writeFieldEnd();
  }
  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}


FileInfoExtractService_uploadFile_presult::~FileInfoExtractService_uploadFile_presult() throw() {
}


uint32_t FileInfoExtractService_uploadFile_presult::read(::apache::thrift::protocol::TProtocol* iprot) {

  ::apache::thrift::protocol::TInputRecursionTracker tracker(*iprot);
  uint32_t xfer = 0;
  std::string fname;
  ::apache::thrift::protocol::TType ftype;
  int16_t fid;

  xfer += iprot->readStructBegin(fname);

  using ::apache::thrift::protocol::TProtocolException;


  while (true)
  {
    xfer += iprot->readFieldBegin(fname, ftype, fid);
    if (ftype == ::apache::thrift::protocol::T_STOP) {
      break;
    }
    switch (fid)
    {
      case 0:
        if (ftype == ::apache::thrift::protocol::T_BOOL) {
          xfer += iprot->readBool((*(this->success)));
          this->__isset.success = true;
        } else {
          xfer += iprot->skip(ftype);
        }
        break;
      default:
        xfer += iprot->skip(ftype);
        break;
    }
    xfer += iprot->readFieldEnd();
  }

  xfer += iprot->readStructEnd();

  return xfer;
}

uint32_t FileInfoExtractService_uploadFile_presult::write(::apache::thrift::protocol::TProtocol* oprot) const {
  uint32_t xfer = 0;
  ::apache::thrift::protocol::TOutputRecursionTracker tracker(*oprot);
  xfer += oprot->writeStructBegin("FileInfoExtractService_uploadFile_presult");

  xfer += oprot->writeFieldBegin("success", ::apache::thrift::protocol::T_BOOL, 0);
  xfer += oprot->writeBool((*(this->success)));
  xfer += oprot->writeFieldEnd();

  xfer += oprot->writeFieldStop();
  xfer += oprot->writeStructEnd();
  return xfer;
}

bool FileInfoExtractServiceClient::uploadFile(const FileData& filedata)
{
  send_uploadFile(filedata);
  return recv_uploadFile();
}

void FileInfoExtractServiceClient::send_uploadFile(const FileData& filedata)
{
  int32_t cseqid = 0;
  oprot_->writeMessageBegin("uploadFile", ::apache::thrift::protocol::T_CALL, cseqid);

  FileInfoExtractService_uploadFile_pargs args;
  args.filedata = &filedata;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

bool FileInfoExtractServiceClient::recv_uploadFile()
{

  int32_t rseqid = 0;
  std::string fname;
  ::apache::thrift::protocol::TMessageType mtype;

  iprot_->readMessageBegin(fname, mtype, rseqid);
  if (mtype == ::apache::thrift::protocol::T_EXCEPTION) {
    ::apache::thrift::TApplicationException x;
    x.read(iprot_);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
    throw x;
  }
  if (mtype != ::apache::thrift::protocol::T_REPLY) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
  if (fname.compare("uploadFile") != 0) {
    iprot_->skip(::apache::thrift::protocol::T_STRUCT);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();
  }
  bool _return;
  FileInfoExtractService_uploadFile_presult result;
  result.success = &_return;
  result.read(iprot_);
  iprot_->readMessageEnd();
  iprot_->getTransport()->readEnd();

  if (result.__isset.success) {
    return _return;
  }
  throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "uploadFile failed: unknown result");
}

bool FileInfoExtractServiceProcessor::dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext) {
  ProcessMap::iterator pfn;
  pfn = processMap_.find(fname);
  if (pfn == processMap_.end()) {
    iprot->skip(::apache::thrift::protocol::T_STRUCT);
    iprot->readMessageEnd();
    iprot->getTransport()->readEnd();
    ::apache::thrift::TApplicationException x(::apache::thrift::TApplicationException::UNKNOWN_METHOD, "Invalid method name: '"+fname+"'");
    oprot->writeMessageBegin(fname, ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return true;
  }
  (this->*(pfn->second))(seqid, iprot, oprot, callContext);
  return true;
}

void FileInfoExtractServiceProcessor::process_uploadFile(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext)
{
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("FileInfoExtractService.uploadFile", callContext);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "FileInfoExtractService.uploadFile");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preRead(ctx, "FileInfoExtractService.uploadFile");
  }

  FileInfoExtractService_uploadFile_args args;
  args.read(iprot);
  iprot->readMessageEnd();
  uint32_t bytes = iprot->getTransport()->readEnd();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postRead(ctx, "FileInfoExtractService.uploadFile", bytes);
  }

  FileInfoExtractService_uploadFile_result result;
  try {
    result.success = iface_->uploadFile(args.filedata);
    result.__isset.success = true;
  } catch (const std::exception& e) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "FileInfoExtractService.uploadFile");
    }

    ::apache::thrift::TApplicationException x(e.what());
    oprot->writeMessageBegin("uploadFile", ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return;
  }

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "FileInfoExtractService.uploadFile");
  }

  oprot->writeMessageBegin("uploadFile", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "FileInfoExtractService.uploadFile", bytes);
  }
}

::apache::thrift::stdcxx::shared_ptr< ::apache::thrift::TProcessor > FileInfoExtractServiceProcessorFactory::getProcessor(const ::apache::thrift::TConnectionInfo& connInfo) {
  ::apache::thrift::ReleaseHandler< FileInfoExtractServiceIfFactory > cleanup(handlerFactory_);
  ::apache::thrift::stdcxx::shared_ptr< FileInfoExtractServiceIf > handler(handlerFactory_->getHandler(connInfo), cleanup);
  ::apache::thrift::stdcxx::shared_ptr< ::apache::thrift::TProcessor > processor(new FileInfoExtractServiceProcessor(handler));
  return processor;
}

bool FileInfoExtractServiceConcurrentClient::uploadFile(const FileData& filedata)
{
  int32_t seqid = send_uploadFile(filedata);
  return recv_uploadFile(seqid);
}

int32_t FileInfoExtractServiceConcurrentClient::send_uploadFile(const FileData& filedata)
{
  int32_t cseqid = this->sync_.generateSeqId();
  ::apache::thrift::async::TConcurrentSendSentry sentry(&this->sync_);
  oprot_->writeMessageBegin("uploadFile", ::apache::thrift::protocol::T_CALL, cseqid);

  FileInfoExtractService_uploadFile_pargs args;
  args.filedata = &filedata;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();

  sentry.commit();
  return cseqid;
}

bool FileInfoExtractServiceConcurrentClient::recv_uploadFile(const int32_t seqid)
{

  int32_t rseqid = 0;
  std::string fname;
  ::apache::thrift::protocol::TMessageType mtype;

  // the read mutex gets dropped and reacquired as part of waitForWork()
  // The destructor of this sentry wakes up other clients
  ::apache::thrift::async::TConcurrentRecvSentry sentry(&this->sync_, seqid);

  while(true) {
    if(!this->sync_.getPending(fname, mtype, rseqid)) {
      iprot_->readMessageBegin(fname, mtype, rseqid);
    }
    if(seqid == rseqid) {
      if (mtype == ::apache::thrift::protocol::T_EXCEPTION) {
        ::apache::thrift::TApplicationException x;
        x.read(iprot_);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();
        sentry.commit();
        throw x;
      }
      if (mtype != ::apache::thrift::protocol::T_REPLY) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();
      }
      if (fname.compare("uploadFile") != 0) {
        iprot_->skip(::apache::thrift::protocol::T_STRUCT);
        iprot_->readMessageEnd();
        iprot_->getTransport()->readEnd();

        // in a bad state, don't commit
        using ::apache::thrift::protocol::TProtocolException;
        throw TProtocolException(TProtocolException::INVALID_DATA);
      }
      bool _return;
      FileInfoExtractService_uploadFile_presult result;
      result.success = &_return;
      result.read(iprot_);
      iprot_->readMessageEnd();
      iprot_->getTransport()->readEnd();

      if (result.__isset.success) {
        sentry.commit();
        return _return;
      }
      // in a bad state, don't commit
      throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "uploadFile failed: unknown result");
    }
    // seqid != rseqid
    this->sync_.updatePending(fname, mtype, rseqid);

    // this will temporarily unlock the readMutex, and let other clients get work done
    this->sync_.waitForWork(seqid);
  } // end while(true)
}

void FileInfoExtractServiceCobClient::uploadFile(::apache::thrift::stdcxx::function<void(FileInfoExtractServiceCobClient* client)> cob, const FileData& filedata)
{
  send_uploadFile(filedata);
  channel_->sendAndRecvMessage(::apache::thrift::stdcxx::bind(cob, this), otrans_.get(), itrans_.get());
}

void FileInfoExtractServiceCobClient::send_uploadFile(const FileData& filedata)
{
  int32_t cseqid = 0;
  otrans_->resetBuffer();
  oprot_->writeMessageBegin("uploadFile", ::apache::thrift::protocol::T_CALL, cseqid);

  FileInfoExtractService_uploadFile_pargs args;
  args.filedata = &filedata;
  args.write(oprot_);

  oprot_->writeMessageEnd();
  oprot_->getTransport()->writeEnd();
  oprot_->getTransport()->flush();
}

bool FileInfoExtractServiceCobClient::recv_uploadFile()
{

  int32_t rseqid = 0;
  std::string fname;
  ::apache::thrift::protocol::TMessageType mtype;
  bool completed = false;

  try {
    iprot_->readMessageBegin(fname, mtype, rseqid);
    if (mtype == ::apache::thrift::protocol::T_EXCEPTION) {
      ::apache::thrift::TApplicationException x;
      x.read(iprot_);
      iprot_->readMessageEnd();
      iprot_->getTransport()->readEnd();
      completed = true;
      completed__(true);
      throw x;
    }
    if (mtype != ::apache::thrift::protocol::T_REPLY) {
      iprot_->skip(::apache::thrift::protocol::T_STRUCT);
      iprot_->readMessageEnd();
      iprot_->getTransport()->readEnd();
      completed = true;
      completed__(false);
    }
    if (fname.compare("uploadFile") != 0) {
      iprot_->skip(::apache::thrift::protocol::T_STRUCT);
      iprot_->readMessageEnd();
      iprot_->getTransport()->readEnd();
      completed = true;
      completed__(false);
    }
    bool _return;
    FileInfoExtractService_uploadFile_presult result;
    result.success = &_return;
    result.read(iprot_);
    iprot_->readMessageEnd();
    iprot_->getTransport()->readEnd();

    if (result.__isset.success) {
      completed = true;
      completed__(true);
      return _return;
    }
    completed = true;
    completed__(true);
    throw ::apache::thrift::TApplicationException(::apache::thrift::TApplicationException::MISSING_RESULT, "uploadFile failed: unknown result");
  } catch (...) {
    if (!completed) {
      completed__(false);
    }
    throw;
  }
}

void FileInfoExtractServiceAsyncProcessor::dispatchCall(::apache::thrift::stdcxx::function<void(bool ok)> cob, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid) {
  ProcessMap::iterator pfn;
  pfn = processMap_.find(fname);
  if (pfn == processMap_.end()) {
    iprot->skip(::apache::thrift::protocol::T_STRUCT);
    iprot->readMessageEnd();
    iprot->getTransport()->readEnd();
    ::apache::thrift::TApplicationException x(::apache::thrift::TApplicationException::UNKNOWN_METHOD, "Invalid method name: '"+fname+"'");
    oprot->writeMessageBegin(fname, ::apache::thrift::protocol::T_EXCEPTION, seqid);
    x.write(oprot);
    oprot->writeMessageEnd();
    oprot->getTransport()->writeEnd();
    oprot->getTransport()->flush();
    return cob(true);
  }
  (this->*(pfn->second))(cob, seqid, iprot, oprot);
  return;
}

void FileInfoExtractServiceAsyncProcessor::process_uploadFile(::apache::thrift::stdcxx::function<void(bool ok)> cob, int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot)
{
  FileInfoExtractService_uploadFile_args args;
  void* ctx = NULL;
  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("FileInfoExtractService.uploadFile", NULL);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "FileInfoExtractService.uploadFile");

  try {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->preRead(ctx, "FileInfoExtractService.uploadFile");
    }
    args.read(iprot);
    iprot->readMessageEnd();
    uint32_t bytes = iprot->getTransport()->readEnd();
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->postRead(ctx, "FileInfoExtractService.uploadFile", bytes);
    }
  }
  catch (const std::exception&) {
    if (this->eventHandler_.get() != NULL) {
      this->eventHandler_->handlerError(ctx, "FileInfoExtractService.uploadFile");
    }
    return cob(false);
  }
  freer.unregister();
  void (FileInfoExtractServiceAsyncProcessor::*return_fn)(::apache::thrift::stdcxx::function<void(bool ok)> cob, int32_t seqid, ::apache::thrift::protocol::TProtocol* oprot, void* ctx, const bool& _return) =
    &FileInfoExtractServiceAsyncProcessor::return_uploadFile;
  iface_->uploadFile(
      ::apache::thrift::stdcxx::bind(return_fn, this, cob, seqid, oprot, ctx, ::apache::thrift::stdcxx::placeholders::_1),
      args.filedata);
}

void FileInfoExtractServiceAsyncProcessor::return_uploadFile(::apache::thrift::stdcxx::function<void(bool ok)> cob, int32_t seqid, ::apache::thrift::protocol::TProtocol* oprot, void* ctx, const bool& _return)
{
  FileInfoExtractService_uploadFile_presult result;
  result.success = const_cast<bool*>(&_return);
  result.__isset.success = true;

  if (this->eventHandler_.get() != NULL) {
    ctx = this->eventHandler_->getContext("FileInfoExtractService.uploadFile", NULL);
  }
  ::apache::thrift::TProcessorContextFreer freer(this->eventHandler_.get(), ctx, "FileInfoExtractService.uploadFile");

  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->preWrite(ctx, "FileInfoExtractService.uploadFile");
  }

  oprot->writeMessageBegin("uploadFile", ::apache::thrift::protocol::T_REPLY, seqid);
  result.write(oprot);
  oprot->writeMessageEnd();
  uint32_t bytes = oprot->getTransport()->writeEnd();
  oprot->getTransport()->flush();
  if (this->eventHandler_.get() != NULL) {
    this->eventHandler_->postWrite(ctx, "FileInfoExtractService.uploadFile", bytes);
  }
  return cob(true);
}

::apache::thrift::stdcxx::shared_ptr< ::apache::thrift::async::TAsyncProcessor > FileInfoExtractServiceAsyncProcessorFactory::getProcessor(const ::apache::thrift::TConnectionInfo& connInfo) {
  ::apache::thrift::ReleaseHandler< FileInfoExtractServiceCobSvIfFactory > cleanup(handlerFactory_);
  ::apache::thrift::stdcxx::shared_ptr< FileInfoExtractServiceCobSvIf > handler(handlerFactory_->getHandler(connInfo), cleanup);
  ::apache::thrift::stdcxx::shared_ptr< ::apache::thrift::async::TAsyncProcessor > processor(new FileInfoExtractServiceAsyncProcessor(handler));
  return processor;
}


