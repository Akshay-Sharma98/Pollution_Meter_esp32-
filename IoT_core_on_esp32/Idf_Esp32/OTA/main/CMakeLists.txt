idf_component_register(SRCS "https_ota_example.c"
                            "wifi_functions.c" 
                    INCLUDE_DIRS "."
                    # Embed the server root certificate into the final binary
                    EMBED_TXTFILES ${project_dir}/server_certs/certs.pem)
