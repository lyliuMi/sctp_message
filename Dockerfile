FROM ubuntu:latest

WORKDIR /C++/C/sctp_msg

COPY install/bin/sctp_test_client /C++/C/sctp_msg/install/bin/sctp_test_client

COPY install/bin/sctp_test_server /C++/C/sctp_msg/install/bin/sctp_test_server

RUN chmod +x /C++/C/sctp_msg/install/bin

CMD ["./install/bin/sctp_test_server"]
CMD ["./install/bin/sctp_test_client"]
