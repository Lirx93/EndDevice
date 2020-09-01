FROM avic613/vm.universal.vxworks6.6

COPY out.tar /
RUN chmod 777 /out.tar