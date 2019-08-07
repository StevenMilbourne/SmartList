file(REMOVE_RECURSE
  "libpistache.pdb"
  "libpistache.a"
)

# Per-language clean rules from dependency scanning.
foreach(lang CXX)
  include(CMakeFiles/pistache_static.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
