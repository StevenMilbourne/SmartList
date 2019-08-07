file(REMOVE_RECURSE
  "libpistache.pdb"
  "libpistache.so.0.0.001-git20190623"
  "libpistache.so"
  "libpistache.so.0"
)

# Per-language clean rules from dependency scanning.
foreach(lang CXX)
  include(CMakeFiles/pistache_shared.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
