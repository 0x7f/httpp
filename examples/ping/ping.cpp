/*
 * Part of HTTPP.
 *
 * Distributed under the 2-clause BSD licence (See LICENCE.TXT file at the
 * project root).
 *
 * Copyright (c) 2015 Thomas Sanchez.  All rights reserved.
 *
 */

#include <iostream>
#include <string>
#include <chrono>

#include <httpp/HttpServer.hpp>
#include <httpp/http/Utils.hpp>
#include <httpp/utils/Exception.hpp>

using HTTPP::HttpServer;
using HTTPP::HTTP::Request;
using HTTPP::HTTP::Connection;
using HTTPP::HTTP::helper::ReadWholeRequest;
using HTTPP::HTTP::HttpCode;

void handler(Connection* connection)
{
    read_whole_request(connection, [](std::unique_ptr<ReadWholeRequest> handle,
                                      const boost::system::error_code& ec) {

        if (ec)
        {
            throw HTTPP::UTILS::convert_boost_ec_to_std_ec(ec);
        }

        auto connection = handle->connection;
        connection->response().setCode(HttpCode::Ok);
        HTTPP::HTTP::setShouldConnectionBeClosed(connection->request(),
                                                 connection->response());
        connection->sendResponse(); // connection pointer may become invalid
    });
}

int main(int, char**)
{
    commonpp::core::init_logging();
    commonpp::core::set_logging_level(commonpp::warning);
    HttpServer server(1);
    server.start();
    server.setSink(&handler);
    server.bind("localhost", "8080");
    while (true) std::this_thread::sleep_for(std::chrono::milliseconds(100));
}
