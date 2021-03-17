
import Cocoa

import mlx_window
import mlx_image
import mlx_init

let MLX_SYNC_IMAGE_WRITABLE = Int32(1)
let MLX_SYNC_WIN_FLUSH_CMD = Int32(2)
let MLX_SYNC_WIN_CMD_COMPLETED = Int32(3)

@_cdecl("mlx_get_screen_size")
public func mlx_get_screen_size_swift(_ mlxptr:UnsafeRawPointer, _ sizex:UnsafeMutablePointer<Int32>, _ sizey:UnsafeMutablePointer<Int32>) -> Int32
{
	/// let mlx:MlxMain = _mlx_bridge(ptr:mlxptr)
	sizex.pointee = Int32(NSScreen.main!.frame.size.width)
	sizey.pointee = Int32(NSScreen.main!.frame.size.height)
	return Int32(0)
}
