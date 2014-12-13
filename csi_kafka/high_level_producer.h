#include <csi_kafka/low_level/producer.h>
#pragma once

namespace csi
{
    namespace kafka
    {
        class highlevel_producer
        {
        public:
            typedef boost::function <void(const boost::system::error_code&)> connect_callback;
            highlevel_producer(boost::asio::io_service& io_service, const boost::asio::ip::tcp::resolver::query& query, const std::string& topic);
            boost::system::error_code connect();
            void refresh_metadata_async();
        private:
            boost::asio::io_service&             _ios;
            csi::kafka::low_level::client        _meta_client;
            std::string                          _topic_name;
            std::map<int, producer*>             _producers;
            rpc_result<metadata_response>        _metadata;
        };
    };
};
