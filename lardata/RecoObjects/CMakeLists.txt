art_make(LIB_LIBRARIES lardataobj_AnalysisBase
                       lardataobj_RecoBase
                       larcore_Geometry_Geometry_service
                       larcorealg_Geometry
                       ${ART_FRAMEWORK_CORE}
                       ${ART_FRAMEWORK_SERVICES_REGISTRY}
                       canvas
                       ${FHICLCPP}
                       cetlib_except
                       ${ROOT_CORE}
                       ${ROOT_PHYSICS}
                       ${Boost_SYSTEM_LIBRARY})

install_headers()
install_fhicl()
install_source()
