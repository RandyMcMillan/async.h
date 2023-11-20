TARGET=async/build/example
-:
	@awk 'BEGIN {FS = ":.*?## "} /^[a-zA-Z_-]+:.*?##/ {printf "\033[36m%-15s\033[0m %s\n", $$1, $$2}' $(MAKEFILE_LIST)
help:## 	help
	@sed -n 's/^##//p' ${MAKEFILE_LIST} | column -t -s ':' |  sed -e 's/^/ /'
example:$(TARGET)## 	async/build/example
##example
## example
##  example
$(TARGET):
	@pushd async && $(MAKE) && popd
run:$(TARGET)## 	run
	@$(TARGET)
clean:## 	clean
	rm async/build/example
.PHONY:$(TARGET)
