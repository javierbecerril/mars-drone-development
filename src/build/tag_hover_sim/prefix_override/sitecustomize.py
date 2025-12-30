import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/javierbecerril/harmonic_ws/src/install/tag_hover_sim'
