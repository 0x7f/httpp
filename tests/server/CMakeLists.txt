# Part of HTTPP.
#
# Distributed under the 2-clause BSD licence (See LICENCE.TXT file at the
# project root).
#
# Copyright (c) 2013 Thomas Sanchez.  All rights reserved.
#

set(MODULE "Server")
add_definitions("-DBOOST_TEST_MODULE=${MODULE}")

ADD_HTTPP_TEST(body)
ADD_HTTPP_TEST(start_stop_server)
ADD_HTTPP_TEST(chunked_encoding)
ADD_HTTPP_TEST(pipeline)

