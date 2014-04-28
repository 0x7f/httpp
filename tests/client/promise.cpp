/*
 * Part of HTTPP.
 *
 * Distributed under the 3-clause BSD licence (See LICENCE.TXT file at the
 * project root).
 *
 * Copyright (c) 2014 Thomas Sanchez.  All rights reserved.
 *
 */
#include <iostream>
#include <chrono>
#include <thread>

#include <boost/test/unit_test.hpp>

#include "httpp/HttpServer.hpp"
#include "httpp/HttpClient.hpp"

using namespace HTTPP;


BOOST_AUTO_TEST_CASE(promise)
{

    for (int i = 0; i < 100000; ++i)
    {
        HttpClient client;
        (void)client;
    }
}
