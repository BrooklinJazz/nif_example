# Environment variables passed via elixir_make
# ERTS_INCLUDE_DIR
# MIX_APP_PATH

CFLAGS= -fPIC -I$(ERTS_INCLUDE_DIR) -Wall -w

ifdef DEBUG
    CFLAGS += -g
endif

LDFLAGS = -shared

$(MIX_APP_PATH)/priv/libnifexample.so: c_src/my_nif.cc
		@mkdir -p $(MIX_APP_PATH)/priv
		$(CXX) $(CFLAGS) -c $< -o $@ $(LDFLAGS)