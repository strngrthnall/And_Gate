# Seus sources C++
SOURCES += src/plugin.cpp
SOURCES += src/MyModule.cpp

DISTRIBUTABLES += res

# --- INTEGRAÇÃO RUST COMEÇA AQUI ---

# Caminho para a lib estática gerada pelo Rust
RUST_LIB_DIR = rust-dsp/target/release
RUST_LIB_NAME = dsp_core
RUST_LIB = $(RUST_LIB_DIR)/lib$(RUST_LIB_NAME).a

# Flags para o Linker: diz ao C++ onde achar sua lib Rust e bibliotecas do sistema necessárias (pthread, dl, etc)
LDFLAGS += -L$(RUST_LIB_DIR) -l$(RUST_LIB_NAME)
# Em Linux/Arch, Rust geralmente precisa de ligação com pthread e dl se não for totalmente static
LDFLAGS += -lpthread -ldl 

# Regra para compilar o Rust antes de tudo
$(RUST_LIB):
	cd rust-dsp && cargo build --release

# Força o Make a verificar se o Rust precisa recompilar
.PHONY: rust_build
rust_build: $(RUST_LIB)

include $(RACK_DIR)/plugin.mk

# Adiciona a dependência ao build do plugin
$(TARGET): $(RUST_LIB)

# --- INTEGRAÇÃO RUST TERMINA AQUI ---

include $(RACK_DIR)/plugin.mk