{
	'targets': [
		{
			'target_name': 'Hotkey',
			'sources': [
				'src/ExtensionMain.cpp',
				'src/Hotkey.cpp',
				'src/Hotkey.h',
			],
			'include_dirs': [
				'<(module_root_dir)/src/',
			]
		}
	]
}