package com.project2.util;

import java.io.File;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.UUID;
import org.springframework.stereotype.Component;
import org.springframework.web.multipart.MultipartFile;
import org.springframework.web.multipart.MultipartHttpServletRequest;
import com.project2.domain.BoardVO;

// registry bean to bean class
@Component("fileUtils")
public class FileUtils {
	// file path for file store
	private static final String filePath = "C:\\Users\\alsgu\\Documents\\workspace-sts-3.9.7.RELEASE\\project2\\src\\main\\webapp\\resources\\img\\";

	public Map<String, Object> parseInsertFileInfo(BoardVO boardVO, MultipartHttpServletRequest mhsRequest)
			throws Exception {
		// get id = file from form data
		MultipartFile mpf = mhsRequest.getFile("file");
		// original file name
		String originalFileName = null;
		// extract only file name
		String originalFileExtension = null;
		// stored file name
		String storedFileName = null;

		Map<String, Object> listMap = null;

		int bno = boardVO.getBno();

		File file = new File(filePath);
		// file path not exist exception control
		if (file.exists() == false) {
			file.mkdirs();
		}

		if (mpf.isEmpty() == false) {
			originalFileName = mpf.getOriginalFilename();
			// get original file name
			originalFileExtension = originalFileName.substring(originalFileName.lastIndexOf("."));
			// processing extract only file name
			storedFileName = getRandomString() + originalFileExtension;
			// generate stored file name
			// generate file object for file I/O
			file = new File(filePath + storedFileName);
			// store file for file path
			mpf.transferTo(file);
			listMap = new HashMap<String, Object>();
			listMap.put("bno", bno); // put post number
			listMap.put("org_file_name", originalFileName); // put original name
			listMap.put("stored_file_name", storedFileName); // put stored name
			listMap.put("file_size", mpf.getSize()); // put file size

		}
		return listMap;
	}

	// generate random 32 string for file name
	public static String getRandomString() {
		return UUID.randomUUID().toString().replaceAll("-", "");
	}
}