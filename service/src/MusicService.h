
#include <app/MessageService.h>

namespace os {
namespace app {
namespace xmsservice {

class MusicService : public MessageService {
public:
    void onCreate() override;
    void onBindExt(const Intent &intent);
    void onStartCommand(const Intent &intent) override;
    bool onUnbind() override;
    void onDestroy() override;

    std::string receiveMessageAndReply(const string &request) override;
    void receiveMessage(const std::string &request,
                        const std::shared_ptr<ReplySender> &reply) override;

private:
};

} // namespace xmsservice
} // namespace app
} // namespace os
