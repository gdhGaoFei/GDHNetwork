Pod::Spec.new do |s|

s.name = 'GDHNetwork'
s.version = '1.0.1'
s.license = 'MIT'
s.summary = 'GDHNetwork is a high level request util based on AFNetworking.'
s.homepage = 'https://github.com/gdhGaoFei/GDHNetwork'
s.authors = { 'GaoFei' => 'gdhgaofei@163.com' }
s.source = { :git => 'https://github.com/gdhGaoFei/GDHNetwork.git', :tag => s.version.to_s }
s.requires_arc = true
s.ios.deployment_target = '7.0'
s.source_files = 'GDHNetwork", "*.{h,m}"
s.resources = 'GDHNetwork/images/*.png'
s.dependency "AFNetworking", "~> 3.1.0"
s.dependency "MBProgressHUD", "~> 1.0.0"

end
