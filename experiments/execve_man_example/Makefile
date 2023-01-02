EXECUTABLES=myecho.x execvp.x execve.x execve-na.x execv-na.x

all : $(EXECUTABLES)

%.x : %.c
	gcc $< -o $@

clean :
	-/bin/rm -f $(EXECUTABLES)

demo : all
	@/bin/echo "Running ./execve.x ./myecho.x :"
	@./execve.x ./myecho.x
	@echo
	@/bin/echo "Running ./execve-na.x /usr/bin/env :"
	@./execve-na.x /usr/bin/env
	@echo
	@/bin/echo "Running ./execv-na.x /usr/bin/env :"
	@./execv-na.x /usr/bin/env
