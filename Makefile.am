bin_PROGRAMS = beansdb beansdb_convert
beansdb_SOURCES = src/beansdb.c src/item.c src/fnv1a.h src/beansdb.h src/thread.c src/htree.h src/htree.c src/hint.h src/hint.c src/record.h src/record.c src/codec.h src/codec.c src/bitcask.h src/bitcask.c src/hstore.h src/hstore.c src/quicklz.h src/quicklz.c src/diskmgr.h src/diskmgr.c
beansdb_CPPFLAGS = -DNDEBUG

beansdb_convert_SOURCES = src/convert.c src/fnv1a.h src/htree.h src/htree.c src/hint.h src/hint.c src/record.h src/record.c src/codec.h src/codec.c src/bitcask.h src/bitcask.c src/hstore.h src/hstore.c src/quicklz.h src/quicklz.c src/diskmgr.h src/diskmgr.c

SUBDIRS = doc
EXTRA_DIST = python src/crc32.c src/clock_gettime_stub.c src/ae_epoll.c src/ae_kqueue.c src/ae_select.c CREDITS AUTHORS LICENSE

dist-hook:
	rm -rf $(distdir)/*/.svn/
