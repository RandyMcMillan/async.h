TARGET=async/build/example
default:$(TARGET)
	@$(TARGET)
async/build/example:
	@pushd async && $(MAKE) && popd
clean:
	rm async/build/example

.PHONY:$(TARGET)
