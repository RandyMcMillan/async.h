TARGET=async/build/example
-:
	@awk 'BEGIN {FS = ":.*?## "} /^[a-zA-Z_-]+:.*?##/ {printf "\033[36m%-15s\033[0m %s\n", $$1, $$2}' $(MAKEFILE_LIST)
example:$(TARGET)## 	async/build/example
$(TARGET):
	@pushd async && $(MAKE) && popd
run:$(TARGET)## 	run
	@$(TARGET)
clean:## 	clean
	rm async/build/example
.PHONY:$(TARGET)
