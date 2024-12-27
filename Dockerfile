FROM ubuntu:latest

WORKDIR /C++/C/sctp_msg

COPY install /C++/C/sctp_msg/install

RUN chmod +x /C++/C/sctp_msg/install/bin

CMD ["./install/bin/sctp_test_server"]
CMD ["./install/bin/sctp_test_client"]
