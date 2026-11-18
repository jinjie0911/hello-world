# 定义变量，方便修改
CC = gcc
CFLAGS = -Wall -g

# 最终目标：app 依赖两个.o 文件
app: main.o utils.o
	$(CC) -o $@ $^

# 模式规则：把每个.c 编译成.o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# 清理
.PHONY: clean
clean:
	rm -f app *.o

#/************************************************************/
# 工具链和选项
CC = gcc
CFLAGS = -Wall -O2 -Iinclude
LDFLAGS = -Llib -lmylib

# 目录
SRCDIR = src
BUILDDIR = build
TARGET = $(BUILDDIR)/app

# 自动收集 src 下所有.c 文件
SRCS = $(wildcard $(SRCDIR)/*.c)
# 把 src/xxx.c 替换成 build/xxx.o
OBJS = $(patsubst $(SRCDIR)/%.c,$(BUILDDIR)/%.o,$(SRCS))

# 最终目标
$(TARGET): $(OBJS)
	@mkdir -p $(BUILDDIR)
	$(CC) -o $@ $^ $(LDFLAGS)

# 模式规则：编译到 build 目录
$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# 多目录子项目（如果有）
SUBDIRS = lib tests
all: $(TARGET)
	@for dir in $(SUBDIRS); do $(MAKE) -C $$dir; done

# 清理
.PHONY: clean all
clean:
	rm -rf $(BUILDDIR)
	@for dir in $(SUBDIRS); do $(MAKE) -C $$dir clean; done
