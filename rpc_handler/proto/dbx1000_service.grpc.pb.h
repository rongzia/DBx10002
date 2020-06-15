// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: dbx1000_service.proto
#ifndef GRPC_dbx1000_5fservice_2eproto__INCLUDED
#define GRPC_dbx1000_5fservice_2eproto__INCLUDED

#include "dbx1000_service.pb.h"

#include <functional>
#include <grpcpp/impl/codegen/async_generic_service.h>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/client_context.h>
#include <grpcpp/impl/codegen/completion_queue.h>
#include <grpcpp/impl/codegen/method_handler_impl.h>
#include <grpcpp/impl/codegen/proto_utils.h>
#include <grpcpp/impl/codegen/rpc_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/server_context.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/status.h>
#include <grpcpp/impl/codegen/stub_options.h>
#include <grpcpp/impl/codegen/sync_stream.h>

namespace grpc_impl {
class CompletionQueue;
class ServerCompletionQueue;
class ServerContext;
}  // namespace grpc_impl

namespace grpc {
namespace experimental {
template <typename RequestT, typename ResponseT>
class MessageAllocator;
}  // namespace experimental
}  // namespace grpc

namespace dbx1000 {

class DBx1000Service final {
 public:
  static constexpr char const* service_full_name() {
    return "dbx1000.DBx1000Service";
  }
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    virtual ::grpc::Status LockRemote(::grpc::ClientContext* context, const ::dbx1000::LockRemoteRequest& request, ::dbx1000::LockRemoteReply* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::dbx1000::LockRemoteReply>> AsyncLockRemote(::grpc::ClientContext* context, const ::dbx1000::LockRemoteRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::dbx1000::LockRemoteReply>>(AsyncLockRemoteRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::dbx1000::LockRemoteReply>> PrepareAsyncLockRemote(::grpc::ClientContext* context, const ::dbx1000::LockRemoteRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::dbx1000::LockRemoteReply>>(PrepareAsyncLockRemoteRaw(context, request, cq));
    }
    virtual ::grpc::Status LockInvalid(::grpc::ClientContext* context, const ::dbx1000::LockInvalidRequest& request, ::dbx1000::LockInvalidReply* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::dbx1000::LockInvalidReply>> AsyncLockInvalid(::grpc::ClientContext* context, const ::dbx1000::LockInvalidRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::dbx1000::LockInvalidReply>>(AsyncLockInvalidRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::dbx1000::LockInvalidReply>> PrepareAsyncLockInvalid(::grpc::ClientContext* context, const ::dbx1000::LockInvalidRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::dbx1000::LockInvalidReply>>(PrepareAsyncLockInvalidRaw(context, request, cq));
    }
    class experimental_async_interface {
     public:
      virtual ~experimental_async_interface() {}
      virtual void LockRemote(::grpc::ClientContext* context, const ::dbx1000::LockRemoteRequest* request, ::dbx1000::LockRemoteReply* response, std::function<void(::grpc::Status)>) = 0;
      virtual void LockRemote(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::dbx1000::LockRemoteReply* response, std::function<void(::grpc::Status)>) = 0;
      virtual void LockRemote(::grpc::ClientContext* context, const ::dbx1000::LockRemoteRequest* request, ::dbx1000::LockRemoteReply* response, ::grpc::experimental::ClientUnaryReactor* reactor) = 0;
      virtual void LockRemote(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::dbx1000::LockRemoteReply* response, ::grpc::experimental::ClientUnaryReactor* reactor) = 0;
      virtual void LockInvalid(::grpc::ClientContext* context, const ::dbx1000::LockInvalidRequest* request, ::dbx1000::LockInvalidReply* response, std::function<void(::grpc::Status)>) = 0;
      virtual void LockInvalid(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::dbx1000::LockInvalidReply* response, std::function<void(::grpc::Status)>) = 0;
      virtual void LockInvalid(::grpc::ClientContext* context, const ::dbx1000::LockInvalidRequest* request, ::dbx1000::LockInvalidReply* response, ::grpc::experimental::ClientUnaryReactor* reactor) = 0;
      virtual void LockInvalid(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::dbx1000::LockInvalidReply* response, ::grpc::experimental::ClientUnaryReactor* reactor) = 0;
    };
    virtual class experimental_async_interface* experimental_async() { return nullptr; }
  private:
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::dbx1000::LockRemoteReply>* AsyncLockRemoteRaw(::grpc::ClientContext* context, const ::dbx1000::LockRemoteRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::dbx1000::LockRemoteReply>* PrepareAsyncLockRemoteRaw(::grpc::ClientContext* context, const ::dbx1000::LockRemoteRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::dbx1000::LockInvalidReply>* AsyncLockInvalidRaw(::grpc::ClientContext* context, const ::dbx1000::LockInvalidRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::dbx1000::LockInvalidReply>* PrepareAsyncLockInvalidRaw(::grpc::ClientContext* context, const ::dbx1000::LockInvalidRequest& request, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub final : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel);
    ::grpc::Status LockRemote(::grpc::ClientContext* context, const ::dbx1000::LockRemoteRequest& request, ::dbx1000::LockRemoteReply* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::dbx1000::LockRemoteReply>> AsyncLockRemote(::grpc::ClientContext* context, const ::dbx1000::LockRemoteRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::dbx1000::LockRemoteReply>>(AsyncLockRemoteRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::dbx1000::LockRemoteReply>> PrepareAsyncLockRemote(::grpc::ClientContext* context, const ::dbx1000::LockRemoteRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::dbx1000::LockRemoteReply>>(PrepareAsyncLockRemoteRaw(context, request, cq));
    }
    ::grpc::Status LockInvalid(::grpc::ClientContext* context, const ::dbx1000::LockInvalidRequest& request, ::dbx1000::LockInvalidReply* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::dbx1000::LockInvalidReply>> AsyncLockInvalid(::grpc::ClientContext* context, const ::dbx1000::LockInvalidRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::dbx1000::LockInvalidReply>>(AsyncLockInvalidRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::dbx1000::LockInvalidReply>> PrepareAsyncLockInvalid(::grpc::ClientContext* context, const ::dbx1000::LockInvalidRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::dbx1000::LockInvalidReply>>(PrepareAsyncLockInvalidRaw(context, request, cq));
    }
    class experimental_async final :
      public StubInterface::experimental_async_interface {
     public:
      void LockRemote(::grpc::ClientContext* context, const ::dbx1000::LockRemoteRequest* request, ::dbx1000::LockRemoteReply* response, std::function<void(::grpc::Status)>) override;
      void LockRemote(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::dbx1000::LockRemoteReply* response, std::function<void(::grpc::Status)>) override;
      void LockRemote(::grpc::ClientContext* context, const ::dbx1000::LockRemoteRequest* request, ::dbx1000::LockRemoteReply* response, ::grpc::experimental::ClientUnaryReactor* reactor) override;
      void LockRemote(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::dbx1000::LockRemoteReply* response, ::grpc::experimental::ClientUnaryReactor* reactor) override;
      void LockInvalid(::grpc::ClientContext* context, const ::dbx1000::LockInvalidRequest* request, ::dbx1000::LockInvalidReply* response, std::function<void(::grpc::Status)>) override;
      void LockInvalid(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::dbx1000::LockInvalidReply* response, std::function<void(::grpc::Status)>) override;
      void LockInvalid(::grpc::ClientContext* context, const ::dbx1000::LockInvalidRequest* request, ::dbx1000::LockInvalidReply* response, ::grpc::experimental::ClientUnaryReactor* reactor) override;
      void LockInvalid(::grpc::ClientContext* context, const ::grpc::ByteBuffer* request, ::dbx1000::LockInvalidReply* response, ::grpc::experimental::ClientUnaryReactor* reactor) override;
     private:
      friend class Stub;
      explicit experimental_async(Stub* stub): stub_(stub) { }
      Stub* stub() { return stub_; }
      Stub* stub_;
    };
    class experimental_async_interface* experimental_async() override { return &async_stub_; }

   private:
    std::shared_ptr< ::grpc::ChannelInterface> channel_;
    class experimental_async async_stub_{this};
    ::grpc::ClientAsyncResponseReader< ::dbx1000::LockRemoteReply>* AsyncLockRemoteRaw(::grpc::ClientContext* context, const ::dbx1000::LockRemoteRequest& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::dbx1000::LockRemoteReply>* PrepareAsyncLockRemoteRaw(::grpc::ClientContext* context, const ::dbx1000::LockRemoteRequest& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::dbx1000::LockInvalidReply>* AsyncLockInvalidRaw(::grpc::ClientContext* context, const ::dbx1000::LockInvalidRequest& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::dbx1000::LockInvalidReply>* PrepareAsyncLockInvalidRaw(::grpc::ClientContext* context, const ::dbx1000::LockInvalidRequest& request, ::grpc::CompletionQueue* cq) override;
    const ::grpc::internal::RpcMethod rpcmethod_LockRemote_;
    const ::grpc::internal::RpcMethod rpcmethod_LockInvalid_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    virtual ::grpc::Status LockRemote(::grpc::ServerContext* context, const ::dbx1000::LockRemoteRequest* request, ::dbx1000::LockRemoteReply* response);
    virtual ::grpc::Status LockInvalid(::grpc::ServerContext* context, const ::dbx1000::LockInvalidRequest* request, ::dbx1000::LockInvalidReply* response);
  };
  template <class BaseClass>
  class WithAsyncMethod_LockRemote : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_LockRemote() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_LockRemote() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status LockRemote(::grpc::ServerContext* context, const ::dbx1000::LockRemoteRequest* request, ::dbx1000::LockRemoteReply* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestLockRemote(::grpc::ServerContext* context, ::dbx1000::LockRemoteRequest* request, ::grpc::ServerAsyncResponseWriter< ::dbx1000::LockRemoteReply>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_LockInvalid : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithAsyncMethod_LockInvalid() {
      ::grpc::Service::MarkMethodAsync(1);
    }
    ~WithAsyncMethod_LockInvalid() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status LockInvalid(::grpc::ServerContext* context, const ::dbx1000::LockInvalidRequest* request, ::dbx1000::LockInvalidReply* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestLockInvalid(::grpc::ServerContext* context, ::dbx1000::LockInvalidRequest* request, ::grpc::ServerAsyncResponseWriter< ::dbx1000::LockInvalidReply>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(1, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  typedef WithAsyncMethod_LockRemote<WithAsyncMethod_LockInvalid<Service > > AsyncService;
  template <class BaseClass>
  class ExperimentalWithCallbackMethod_LockRemote : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    ExperimentalWithCallbackMethod_LockRemote() {
      ::grpc::Service::experimental().MarkMethodCallback(0,
        new ::grpc_impl::internal::CallbackUnaryHandler< ::dbx1000::LockRemoteRequest, ::dbx1000::LockRemoteReply>(
          [this](::grpc::ServerContext* context,
                 const ::dbx1000::LockRemoteRequest* request,
                 ::dbx1000::LockRemoteReply* response,
                 ::grpc::experimental::ServerCallbackRpcController* controller) {
                   return this->LockRemote(context, request, response, controller);
                 }));
    }
    void SetMessageAllocatorFor_LockRemote(
        ::grpc::experimental::MessageAllocator< ::dbx1000::LockRemoteRequest, ::dbx1000::LockRemoteReply>* allocator) {
      static_cast<::grpc_impl::internal::CallbackUnaryHandler< ::dbx1000::LockRemoteRequest, ::dbx1000::LockRemoteReply>*>(
          ::grpc::Service::experimental().GetHandler(0))
              ->SetMessageAllocator(allocator);
    }
    ~ExperimentalWithCallbackMethod_LockRemote() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status LockRemote(::grpc::ServerContext* context, const ::dbx1000::LockRemoteRequest* request, ::dbx1000::LockRemoteReply* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual void LockRemote(::grpc::ServerContext* context, const ::dbx1000::LockRemoteRequest* request, ::dbx1000::LockRemoteReply* response, ::grpc::experimental::ServerCallbackRpcController* controller) { controller->Finish(::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "")); }
  };
  template <class BaseClass>
  class ExperimentalWithCallbackMethod_LockInvalid : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    ExperimentalWithCallbackMethod_LockInvalid() {
      ::grpc::Service::experimental().MarkMethodCallback(1,
        new ::grpc_impl::internal::CallbackUnaryHandler< ::dbx1000::LockInvalidRequest, ::dbx1000::LockInvalidReply>(
          [this](::grpc::ServerContext* context,
                 const ::dbx1000::LockInvalidRequest* request,
                 ::dbx1000::LockInvalidReply* response,
                 ::grpc::experimental::ServerCallbackRpcController* controller) {
                   return this->LockInvalid(context, request, response, controller);
                 }));
    }
    void SetMessageAllocatorFor_LockInvalid(
        ::grpc::experimental::MessageAllocator< ::dbx1000::LockInvalidRequest, ::dbx1000::LockInvalidReply>* allocator) {
      static_cast<::grpc_impl::internal::CallbackUnaryHandler< ::dbx1000::LockInvalidRequest, ::dbx1000::LockInvalidReply>*>(
          ::grpc::Service::experimental().GetHandler(1))
              ->SetMessageAllocator(allocator);
    }
    ~ExperimentalWithCallbackMethod_LockInvalid() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status LockInvalid(::grpc::ServerContext* context, const ::dbx1000::LockInvalidRequest* request, ::dbx1000::LockInvalidReply* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual void LockInvalid(::grpc::ServerContext* context, const ::dbx1000::LockInvalidRequest* request, ::dbx1000::LockInvalidReply* response, ::grpc::experimental::ServerCallbackRpcController* controller) { controller->Finish(::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "")); }
  };
  typedef ExperimentalWithCallbackMethod_LockRemote<ExperimentalWithCallbackMethod_LockInvalid<Service > > ExperimentalCallbackService;
  template <class BaseClass>
  class WithGenericMethod_LockRemote : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_LockRemote() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_LockRemote() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status LockRemote(::grpc::ServerContext* context, const ::dbx1000::LockRemoteRequest* request, ::dbx1000::LockRemoteReply* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_LockInvalid : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithGenericMethod_LockInvalid() {
      ::grpc::Service::MarkMethodGeneric(1);
    }
    ~WithGenericMethod_LockInvalid() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status LockInvalid(::grpc::ServerContext* context, const ::dbx1000::LockInvalidRequest* request, ::dbx1000::LockInvalidReply* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithRawMethod_LockRemote : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithRawMethod_LockRemote() {
      ::grpc::Service::MarkMethodRaw(0);
    }
    ~WithRawMethod_LockRemote() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status LockRemote(::grpc::ServerContext* context, const ::dbx1000::LockRemoteRequest* request, ::dbx1000::LockRemoteReply* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestLockRemote(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncResponseWriter< ::grpc::ByteBuffer>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithRawMethod_LockInvalid : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithRawMethod_LockInvalid() {
      ::grpc::Service::MarkMethodRaw(1);
    }
    ~WithRawMethod_LockInvalid() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status LockInvalid(::grpc::ServerContext* context, const ::dbx1000::LockInvalidRequest* request, ::dbx1000::LockInvalidReply* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestLockInvalid(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncResponseWriter< ::grpc::ByteBuffer>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(1, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class ExperimentalWithRawCallbackMethod_LockRemote : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    ExperimentalWithRawCallbackMethod_LockRemote() {
      ::grpc::Service::experimental().MarkMethodRawCallback(0,
        new ::grpc_impl::internal::CallbackUnaryHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
          [this](::grpc::ServerContext* context,
                 const ::grpc::ByteBuffer* request,
                 ::grpc::ByteBuffer* response,
                 ::grpc::experimental::ServerCallbackRpcController* controller) {
                   this->LockRemote(context, request, response, controller);
                 }));
    }
    ~ExperimentalWithRawCallbackMethod_LockRemote() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status LockRemote(::grpc::ServerContext* context, const ::dbx1000::LockRemoteRequest* request, ::dbx1000::LockRemoteReply* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual void LockRemote(::grpc::ServerContext* context, const ::grpc::ByteBuffer* request, ::grpc::ByteBuffer* response, ::grpc::experimental::ServerCallbackRpcController* controller) { controller->Finish(::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "")); }
  };
  template <class BaseClass>
  class ExperimentalWithRawCallbackMethod_LockInvalid : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    ExperimentalWithRawCallbackMethod_LockInvalid() {
      ::grpc::Service::experimental().MarkMethodRawCallback(1,
        new ::grpc_impl::internal::CallbackUnaryHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
          [this](::grpc::ServerContext* context,
                 const ::grpc::ByteBuffer* request,
                 ::grpc::ByteBuffer* response,
                 ::grpc::experimental::ServerCallbackRpcController* controller) {
                   this->LockInvalid(context, request, response, controller);
                 }));
    }
    ~ExperimentalWithRawCallbackMethod_LockInvalid() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status LockInvalid(::grpc::ServerContext* context, const ::dbx1000::LockInvalidRequest* request, ::dbx1000::LockInvalidReply* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual void LockInvalid(::grpc::ServerContext* context, const ::grpc::ByteBuffer* request, ::grpc::ByteBuffer* response, ::grpc::experimental::ServerCallbackRpcController* controller) { controller->Finish(::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "")); }
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_LockRemote : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithStreamedUnaryMethod_LockRemote() {
      ::grpc::Service::MarkMethodStreamed(0,
        new ::grpc::internal::StreamedUnaryHandler< ::dbx1000::LockRemoteRequest, ::dbx1000::LockRemoteReply>(std::bind(&WithStreamedUnaryMethod_LockRemote<BaseClass>::StreamedLockRemote, this, std::placeholders::_1, std::placeholders::_2)));
    }
    ~WithStreamedUnaryMethod_LockRemote() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status LockRemote(::grpc::ServerContext* context, const ::dbx1000::LockRemoteRequest* request, ::dbx1000::LockRemoteReply* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedLockRemote(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::dbx1000::LockRemoteRequest,::dbx1000::LockRemoteReply>* server_unary_streamer) = 0;
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_LockInvalid : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service *service) {}
   public:
    WithStreamedUnaryMethod_LockInvalid() {
      ::grpc::Service::MarkMethodStreamed(1,
        new ::grpc::internal::StreamedUnaryHandler< ::dbx1000::LockInvalidRequest, ::dbx1000::LockInvalidReply>(std::bind(&WithStreamedUnaryMethod_LockInvalid<BaseClass>::StreamedLockInvalid, this, std::placeholders::_1, std::placeholders::_2)));
    }
    ~WithStreamedUnaryMethod_LockInvalid() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status LockInvalid(::grpc::ServerContext* context, const ::dbx1000::LockInvalidRequest* request, ::dbx1000::LockInvalidReply* response) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedLockInvalid(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::dbx1000::LockInvalidRequest,::dbx1000::LockInvalidReply>* server_unary_streamer) = 0;
  };
  typedef WithStreamedUnaryMethod_LockRemote<WithStreamedUnaryMethod_LockInvalid<Service > > StreamedUnaryService;
  typedef Service SplitStreamedService;
  typedef WithStreamedUnaryMethod_LockRemote<WithStreamedUnaryMethod_LockInvalid<Service > > StreamedService;
};

}  // namespace dbx1000


#endif  // GRPC_dbx1000_5fservice_2eproto__INCLUDED