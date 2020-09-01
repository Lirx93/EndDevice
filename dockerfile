FROM vm/universal/vxworks:6.6

COPY out.tar /
RUN chmod 777 /out.tar